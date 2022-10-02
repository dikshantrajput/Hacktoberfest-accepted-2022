window.onload = function(){
    startClock();
}

let time = document.getElementById('time');

let currentData = new Date(); 

let date = currentData.getDate();
let day = currentData.getDay();
let month = currentData.getMonth();
let year = currentData.getFullYear();


let days = ['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday'];

day = days[day];

function startClock(){
    
    let currentData = new Date();
    let seconds = currentData.getSeconds();
    let minutes = currentData.getMinutes();
    let hours = currentData.getHours();
    

    let AMorPM;
    if(hours>=12){
        AMorPM = "PM";
    }
    else{
        AMorPM = "AM";
    }

    let h = hours;
    if(hours==0){
        h = 12;
    }
    else if(hours>12){
        h = hours-12;
    }

    let s = check(seconds);
    let m = check(minutes);
    function check(val){
        if(val<10){
            return '0' + val;
        }
        return val;
    }

    time.innerText = h + ':' + m + ':' + s + ' '+AMorPM;
}

document.getElementById('date').innerText = date+'/ '+month+'/ '+year;
document.getElementById('day').innerText = day;


setInterval(startClock,1000);
