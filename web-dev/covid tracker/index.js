const btn=document.querySelector('.btn');
const input=document.querySelector('.inputELemnt');


btn.addEventListener('click',getdata);
function getdata(){
    let country=input.value;

    const options = {
        method: 'GET',
        headers: {
            'X-RapidAPI-Key': 'd4fba4d46cmsh227fa8a927e7844p10f1ecjsn9d2725619a0d',
            'X-RapidAPI-Host': 'covid-193.p.rapidapi.com'
        }
    };
    
    fetch(`https://covid-193.p.rapidapi.com/statistics?country=${country}`, options)
        .then(response => response.json())
        .then((json)=>{
           
            let data= json.response[0];
            document.querySelector('.activecases').innerHTML=data.cases.active;
            document.querySelector('.newcases').innerHTML=data.cases.new;
            document.querySelector('.recovercases').innerHTML=data.cases.recovered;
            document.querySelector('.totalcases').innerHTML=data.cases.total;
            document.querySelector('.totalDeaths').innerHTML=data.deaths.total;
            document.querySelector('.totaltests').innerHTML=data.tests.total;
        });
       
        
        
    
    
}