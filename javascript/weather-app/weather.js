$(document).ready(function(){
    //function to get user's longitude/latitude and
  var latitude  ;
  var longitude  ;
    
    //check user's browser supports geolocation
  function getLocation() {
      if (navigator.geolocation) {
          navigator.geolocation.getCurrentPosition(showPosition);
      } else {
          lonLat.innerHTML = "Geolocation is not supported by this browser.";
      }
  }
    
    //get user's longitude/latitude
  function showPosition(position) {
    longitude = position.coords.longitude;
    latitude = position.coords.latitude;
    
    //api call to open weather using longitude/latitude
    var api = "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude + "&appid=5029b91e09b130c199a20ae61675e741&units=metric";
    
   $.getJSON(api, function(data){
      console.log(data);
      $('.weather').html('<p>The forecast today for<br> the next 3 hours is... <br><br>' + data.weather[0].description +' </p>');
     var temperature = data.main.temp;
     var temperatureRound = Math.round(temperature);
     
     //set test variable
     var test = 1;
     $('.temperatureButton').on("click", function(){
       //function to alter test var on click
       function setTestToOne(){
         return test = 1;
       }
       function setTestToTwo(){
         return test = 2;
       }
       if (test == 1){
         
       //convert celsius to fahrenheit
       var temperatureFaren = ((temperatureRound * 9) / 5) + 32;
       $('.temperatureButton').html('<button type="button" class="btn btn-default fontStyle">' + temperatureFaren  + '&#8457</button>');
         setTestToTwo();
       }
       else{
         $('.temperatureButton').html('<button type="button" class="btn btn-default fontStyle">' + temperatureRound + '&#8451</button>');
         setTestToOne();
       }
     });
     //get wind speed
     $('.windSpeed').html('Wind Speed ' + data.wind.speed + ' mph');
     
     //insert temperature rounded off figure
     $('.temperatureButton').html('<button type="button" class="btn btn-default fontStyle">' + temperatureRound + '&#8451</button>');
     
     //insert current weather logo
     var imgLogoId = data.weather[0].icon;
     document.getElementById("weatherLogo").src = "http://openweathermap.org/img/w/" + imgLogoId + ".png";
      
     //get current date
     document.getElementById("date").innerHTML = Date();
    })
    //Get county, city, town or village using longitude/latitude + country
       var locationTC = "https://maps.googleapis.com/maps/api/geocode/json?latlng=" + latitude + "," + longitude + " &key=AIzaSyCKpTlOpHjt-wD30HL5_b38cODmmxuxbMc";
    $.getJSON(locationTC, function(data){
      $('.townCity').html('<p>' + data.results[0].address_components[2].long_name +  ', ' + data.results[0].address_components[6].short_name  +'</p>');
    });
  }
    //call for function to get user's longitude/latitude
  getLocation();
  });
  