const sound = new Audio("clock-voice.mp3") 
 
 
 setInterval(() => {
    setInterval(() => {
        sound.play();
        d = new Date();
        htime = d.getHours();
        mtime = d.getMinutes();
        stime = d.getSeconds();
        hrotation = 30*htime + mtime/2;
        mrotation = 6*mtime;
        srotation = 6*stime;
    
        hour.style.transform = `rotate(${hrotation}deg)`;
        minute.style.transform = `rotate(${mrotation}deg)`;
        second.style.transform = `rotate(${srotation}deg)`;
    }, 1000);
 }, 1000);