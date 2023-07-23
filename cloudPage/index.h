const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<link href="https://fonts.googleapis.com/css2?family=Poppins:wght@400;700&display=swap" rel="stylesheet">
<script src="https://code.highcharts.com/highcharts.js"></script>
<style>
body {
  font-family: 'Poppins', sans-serif;
  background-color: #f8f4ec;
}
.navbar {
  background-color: #f2f2f2;
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  padding: 30px 20px;
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
  display: flex;
  z-index: 1000;
  justify-content: center;
}

.nav-list {
  list-style: none;
  padding: 0;
  margin: 0;
  display: flex;
}

.nav-list li {
  margin-right: 30px;
}
.nav-list li:nth-child(5) {
  margin-right: 0px;
}
.nav-list li a {
  text-decoration: none;
  color: #333;
}

.nav-list li a:hover {
  color: #000;
}

.heading {
  text-align: center;
margin-top: 170px;

}

.heading p {
  font-size: 50px; /* Adjust the font size as needed */
  font-weight: bold;
}

.subheading {
  text-align: center;
}

.subheading p {
  font-size: 40px; /* Adjust the font size as needed */
  font-weight: bold;
}

.subheading1 {
  text-align: center;
}

.subheading1 p {
  font-size: 28px; /* Adjust the font size as needed */
  font-weight: bold;
}

.centeralign1 .subheading1 {
  text-align: center;
}

.centeralign1 .subheading1 p {
  font-size: 28px; /* Adjust the font size as needed */
  font-weight: bold;
}
th {
  align:center;
}
.card-container {
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
}

.card {
  flex: 0 0 380px; /* Set the width of each card */
  margin: 10px;
  padding-left: 20px;
  padding-right: 20px;  
  border: 10px solid white;
  box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
}

.card:nth-child(1) {
  background-color: #faedcb; /* Pastel color for the first card */
}

.card:nth-child(2) {
  background-color: #c9e4de; /* Pastel color for the second card */
}

.card:nth-child(3) {
  background-color: #c6def1; /* Pastel color for the third card */
}

.card:nth-child(4) {
  background-color: #dbcdf0; /* Pastel color for the fourth card */
}

.card:nth-child(5) {
  background-color: #f2c6de; /* Pastel color for the fifth card */
}
span {
	font-size:35px;
}
.fnality .content {
  text-align: center;
font-size:30px;
}
.content{
	padding-left:150px;
	padding-right:150px;
	height:250px;
	color:#7a4d4a;
}
.centeralign {
    display: flex;
  flex-wrap: wrap;
  justify-content: center;
}
.centeralign1 {
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
}
.container1 {
  width:1200px;
  height:500px;
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
}
.contenthyp {
  font-size:24px;
  text-align:center;
  padding-left:150px;
  padding-right:150px;
}
</style>
<body>
<nav class="navbar">
  <ul class="nav-list">
    <li><a href="#fn">Overview</a></li>
    <li><a href="#liveread">Live Readings</a></li>
    <li><a href="#dataviz">Data Visualization</a></li>
    <li><a href="#hypothesis">Hypothesis</a></li>
    <li><a href="#dataAnalytics">Analytics Report</a></li>
  </ul>
</nav>
<section id="fn">
<div class="heading"><p>AUTOMATED PLANTING SOLUTIONS</p></div>
  <div class="fnality">
    <div class="subheading">
      <p>OVERVIEW</p>
    </div>
    <div class="content">
      <b>A plant health monitoring system is a technology-based solution that is used to track and monitor the health of plants. The system typically includes sensors and software that work together to collect and analyse data related to the environment, soil conditions, and plant growth.</b>
    </div>
  </div>
</section>
<br>
<section id="liveread">
<div class ="subheading"><p>LIVE READINGS</p></div>
<div class="card-container">
<div class="card">
  <h2><b>Temperature in &deg;C </b><br><span id="aTemp">0</span></h2><br>
</div>
<div class="card">
  <h2><b>Light Intensity </b><br><span id="bLDR">0</span></h2><br>
</div>
<div class="card">
  <h2><b>Soil Moisture Level </b><br><span id="cMois">0</span></h2><br>
</div>
<div class="card">
  <h2><b>Depth Level</b><br><span id="dDep">0</span></h2><br>
</div>
<div class="card">
  <h2><b>Pump State </b><br><span id="eMotor">0</span></h2><br>
</div>
</div>
</section>
<br>
<section id="dataviz">
<div class ="subheading"><p>DATA VISUALIZATION</p></div>
<div class="centeralign">
<div class ="subheading1"><p>TEMPERATURE SENSOR READING</p></div>
<div id="chart-temperature" class="container1"></div>
<br>
<div class ="subheading1"><p>LIGHT SENSOR READING</p></div>
<div id="chart-ldr" class="container1"></div>
<br>
<div class ="subheading1"><p>SOIL MOISTURE SENSOR READING</p></div>
<div id="chart-moisture" class="container1"></div>
<br>
<div class ="subheading1"><p>DEPTH SENSOR READING</p></div>
<div id="chart-depth" class="container1"></div>
</div>
</section>
<br>
<br>
<section id="hypothesis">
<div class="subheading"><p>HYPOTHESIS</p></div>
<div class="centeralign">
<div class="subheading1"><p>Soil Moisture and Motor State</p></div>
<div class="contenthyp">
<p><b>Null hypothesis (H0): </b>There is no significant correlation between soil moisture and motor state<br>
<b>Alternative hypothesis (H1): </b>There is a significant correlation between soil moisture and motor state.<br>
<b>Point Biserial Correlation Test:</b><br> 
<b>Correlation Coefficient:</b> 0.77<br>
<b>p-value:</b> 0.0176<br>
<b>Conclusion: </b> Observed p value < 0.05, which means we have a strong evidence to reject Null Hypothesis. So, we can conclude that soil moisture and motor state are correlated<br>
</p></div>

</div>
</section>
<br>
<br>
<section id="dataAnalytics">
<div class="subheading"><p>DATA ANALYTICS</p></div>
<div class="subheading1"><p>Predictive Analytics Report</p></h2>  
<div class="centeralign1">
<div class="container">          
  <table class="table table-hover">
    <thead>
      <tr>
        <td><b>Model Name</b></td>
        <td><b>Accuracy</b></td>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>KNN</td>
        <td>98%</td>
      </tr>
      <tr>
        <td>Naive Bayes</td>
        <td>97%</td>
      </tr>
      <tr>
        <td>Logistic Regression</td>
        <td>98.6%</td>
      </tr>
      <tr>
        <td>Decision Tree</td>
        <td>97%</td>
      </tr>
      <tr>
        <td>SVM</td>
        <td>96%</td>
      </tr>
      <tr>
        <td>MLP</td>
        <td>96%</td>
      </tr>
      <tr>
        <td>Gradient Boosting</td>
        <td>99.1%</td>
      </tr>
      <tr>
        <td>xgBoost</td>
        <td>98.9%</td>
      </tr>
      <tr>
        <td>ADABoost</td>
        <td>99.2%</td>
      </tr>
      <tr>
        <td>Cat Boost</td>
        <td>99.1%</td>
      </tr>
      <tr>
        <td>Gaussian Process Classifier</td>
        <td>99.3%</td>
      </tr>
      <tr>
        <td>Bagging Classifier</td>
        <td>99.4%</td>
      </tr>
      <tr>
        <td>Linear Discriminant Analysis</td>
        <td>98.3%</td>
      </tr>
      <tr>
        <td>Quadratic Discriminant Analysis</td>
        <td>98.3%</td>
      </tr>
      <tr>
        <td>Extra Trees Classifier</td>
        <td>98%</td>
      </tr>
      <tr>
        <td>Max Voting</td>
        <td>99.5%</td>
      </tr>
    </tbody>
  </table>
</div>
</div>
</section>
<br>
<script>
var chartT = new Highcharts.Chart({
  chart:{ renderTo : 'chart-temperature' },
  title: {text: 'Temperature'},
  series: [{
    showInLegend: false,
    data: []
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#bd952b' }
  },
  xAxis: { type: 'datetime',
    dateTimeLabelFormats: { second: '%H:%M:%S' }
  },
  yAxis: {
    title: { text: 'Temperature (Celsius)' }
  },
  credits: { enabled: false }
  });

  var chartL = new Highcharts.Chart({
  chart:{ renderTo : 'chart-ldr' },
  title: {text: 'Light Intensity'},
  series: [{
    showInLegend: false,
    data: []
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#418c7b' }
  },
  xAxis: { type: 'datetime',
    dateTimeLabelFormats: { second: '%H:%M:%S' }
  },
  yAxis: {
    title: { text: 'Light Intensity' }
  },
  credits: { enabled: false }
  });

  var chartM = new Highcharts.Chart({
  chart:{ renderTo : 'chart-moisture' },
  title: {text: 'Soil Moisture'},
  series: [{
    showInLegend: false,
    data: []
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#496d8a' }
  },
  xAxis: { type: 'datetime',
    dateTimeLabelFormats: { second: '%H:%M:%S' }
  },
  yAxis: {
    title: { text: 'Soil Moisture' }
  },
  credits: { enabled: false }
  });

  var chartD = new Highcharts.Chart({
  chart:{ renderTo : 'chart-depth' },
  title: {text: 'Water Depth Level'},
  series: [{
    showInLegend: false,
    data: []
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#645280' }
  },
  xAxis: { type: 'datetime',
    dateTimeLabelFormats: { second: '%H:%M:%S' }
  },
  yAxis: {
    title: { text: 'Depth Value' }
  },
  credits: { enabled: false }
  });


setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 2000); //2000mSeconds update rate

function getData() {
    var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var values = this.responseText.split(","); // Split the response by comma and space
      document.getElementById("aTemp").innerHTML = values[0];
      document.getElementById("bLDR").innerHTML = values[1];
      document.getElementById("cMois").innerHTML = values[2];
      document.getElementById("dDep").innerHTML = values[3];
      if(values[4]=='1')
      {
        document.getElementById("eMotor").innerHTML = "ON";
      }
      else
      {
        document.getElementById("eMotor").innerHTML = "OFF";
      }

      var x = (new Date()).getTime(),
      y = parseFloat(values[0]);
      if(chartT.series[0].data.length > 40) {
      chartT.series[0].addPoint([x, y], true, true, true);
      } else {
      chartT.series[0].addPoint([x, y], true, false, true);
      }

      var x = (new Date()).getTime(),
      y = parseInt(values[1]);
      if(chartL.series[0].data.length > 40) {
      chartL.series[0].addPoint([x, y], true, true, true);
      } else {
      chartL.series[0].addPoint([x, y], true, false, true);
      }

      var x = (new Date()).getTime(),
      y = parseInt(values[2]);
      if(chartM.series[0].data.length > 40) {
      chartM.series[0].addPoint([x, y], true, true, true);
      } else {
      chartM.series[0].addPoint([x, y], true, false, true);
      }

      var x = (new Date()).getTime(),
      y = parseInt(values[3]);
      if(chartD.series[0].data.length > 40) {
      chartD.series[0].addPoint([x, y], true, true, true);
      } else {
      chartD.series[0].addPoint([x, y], true, false, true);
      }


    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}
</script>
</body>
</html>
)=====";