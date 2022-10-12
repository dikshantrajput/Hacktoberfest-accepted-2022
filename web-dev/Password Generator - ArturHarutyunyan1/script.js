const result         = document.querySelector('.password')
const slider         = document.querySelector('.slider')
const passwordLength = document.querySelector('.value')
const generator      = document.querySelector('.generator-btn') 
const copyBtn        = document.querySelector('.copy-btn')
const flags          = document.querySelectorAll('.flag')

let upperCase = false
let lowerCase = false
let numbers   = false
let symbols   = false

slider.addEventListener('input', sliderFunction)
generator.addEventListener('click', generatePassword)
copyBtn.addEventListener('click', copyPassword)
function sliderFunction(e){
    let value = e.target.value
    passwordLength.textContent = value
    value = (this.value-this.min)/(this.max-this.min)*100
    this.style.background = 'linear-gradient(to right, #a3ffaf 0%, #a3ffaf ' + value + '%, #08070be6 ' + value + '%, #08070be6 100%)'
}

flags.forEach(flag => {
    flag.addEventListener('click', (e)=>{
        let target   = e.target
        if(!target.hasAttribute('checked')){
            target.setAttribute('checked', '')
        }else if(target.hasAttribute('checked')){
            target.removeAttribute('checked')
        }
    })
})

function generatePassword(){
    let length = slider.value
    let chars    = ''
    let password = ''
    flags.forEach(flag => {
        let id = flag.id
        
        if(flag.hasAttribute('checked')){
            if(id == 'upperCase'){
                upperCase = true
            }
            if(id == 'lowerCase'){
                lowerCase = true
            }
            if(id == 'numbers'){
                numbers = true
            }
            if(id == 'symbols'){
                symbols = true
            }
        }else{
            if(id == 'upperCase'){
                upperCase = false
            }
            if(id == 'lowerCase'){
                lowerCase = false
            }
            if(id == 'numbers'){
                numbers = false
            }
            if(id == 'symbols'){
                symbols = false
            }
        }
    })

    if(upperCase){
        chars += 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'       
    }
    if(lowerCase){
        chars += 'abcdefghijklmnopqrstuvwxyz'
    }
    if(numbers){
        chars += '0123456789'
    }
    if(symbols){
        chars += '!@#$%^&*()_+/.";[]{}|-='
    }

    for(let i = 0; i <= length; i++){
        let random = Math.floor(Math.random() * chars.length)
        password += chars.substring(random, random +1);
    }

    result.textContent = password
}

function copyPassword(){
    let password = result.textContent

    navigator.clipboard.writeText(password)
}