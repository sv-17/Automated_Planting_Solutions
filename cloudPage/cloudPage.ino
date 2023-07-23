#include "secrets.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include <WiFiClient.h>
#include <WebServer.h>

#include "index.h"  //Web page header file 
//from corecode
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>

#define POWER_PIN  17 
#define SIGNAL_PIN 36 
#define LIGHT_SENSOR_PIN 34
#define RELAY_PIN 27
#define oneWireBus 4
#define MOISTURE_PIN 35
#define FAN_PIN 23
//end

#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"
 
//values
float temperatureC;
float temperatureF;
int depthValue = 0;
int soilMoistureValue = 0;
int lightIntensity = 0;
int motorState = 0;
int fanState = 0;
//end
 
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);

WebServer server(80);

void connectAWS()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  Serial.println("Connecting to Wi-Fi");
 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
   //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
//----------------------------------------------------------------
 
  server.on("/", handleRoot);      //This is display page
  server.on("/readADC", handleADC);//To get update of ADC Value only
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);
 
  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.setServer(AWS_IOT_ENDPOINT, 8883);
 
  // Create a message handler
  client.setCallback(messageHandler);
 
  Serial.println("Connecting to AWS IOT");
 
  while (!client.connect(THINGNAME))
  {
    Serial.print(".");
    delay(100);
  }
 
  if (!client.connected())
  {
    Serial.println("AWS IoT Timeout!");
    return;
  }
 
  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
 
  Serial.println("AWS IoT Connected!");
}
void handleADC()
{
  String response = String(temperatureC) + "," + String(lightIntensity) +","+ String(soilMoistureValue) + "," + String(depthValue) + ","+String(motorState) + ","+String(fanState) ;
  server.send(200, "text/plane", response); 
}
void publishMessage(float temperatureC, int depthValue, int soilMoistureValue, int lightIntensity, int motorState, int fanState)
{
  StaticJsonDocument<200> doc;
  doc["Temperature"] = temperatureC;
  doc["DepthLevel"] = depthValue;
  doc["MoistureLevel"] = soilMoistureValue;
  doc["LDRMeasurement"] = lightIntensity;
  doc["Motorstate"] = motorState;
  doc["Fanstate"] = fanState;
  
  char jsonBuffer[512];
  serializeJson(doc, jsonBuffer); // print to client
 
  client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}
 
void messageHandler(char* topic, byte* payload, unsigned int length)
{
  Serial.print("incoming: ");
  Serial.println(topic);
 
  StaticJsonDocument<200> doc;
  deserializeJson(doc, payload);
  const char* message = doc["message"];
  Serial.println(message);
}

void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}


void setup()
{
  Serial.begin(115200);
  connectAWS();
  sensors.begin();
  pinMode(POWER_PIN, OUTPUT);   
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(POWER_PIN, LOW);
  digitalWrite(RELAY_PIN, HIGH); 
}
 
void loop()
{
  server.handleClient();
  //sensor measures - start
  //TEMPERATURE
  sensors.requestTemperatures(); 
  temperatureC = sensors.getTempCByIndex(0);
  temperatureF = sensors.getTempFByIndex(0);
  Serial.print("Temperature in Celcius:");
  Serial.println(temperatureC);
  Serial.print("Temperature in Fahrenheit:");
  Serial.println(temperatureF);

  //DEPTH
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  depthValue = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("Depth sensor reading :");
  Serial.println(depthValue);

  //LIGHT
  lightIntensity = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("Light Intensity: ");
  Serial.println(lightIntensity);   // the raw analog reading

  //MOISTURE
  soilMoistureValue = analogRead(MOISTURE_PIN);  //put Sensor insert into soil
  Serial.print("Moisture Sensor:");
  Serial.println(soilMoistureValue);

  if ((soilMoistureValue > 2700) && (depthValue > 1350))
  {
    digitalWrite(RELAY_PIN, LOW); 
    motorState=1;
  }
  else
  {
    digitalWrite(RELAY_PIN,HIGH);
    motorState=0;
  }

  if (temperatureC > 37)
  {
    digitalWrite(FAN_PIN, LOW); 
    fanState=1;
  }
  else
  {
    digitalWrite(FAN_PIN, HIGH); 
    fanState=0;
  }
  
  Serial.print("Motor State:");
  Serial.println(motorState);
  Serial.print("Fan State:");
  Serial.println(fanState);
  //sensor measures - end
  
  publishMessage(temperatureC,depthValue,soilMoistureValue,lightIntensity,motorState,fanState);
  client.loop();
  delay(1000);
}