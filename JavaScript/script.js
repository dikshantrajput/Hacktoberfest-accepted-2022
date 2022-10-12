// Author: Chantae
// Github: https://github.com/taepal467
// This is a random number game where you have to choose a number between 1 and 10
// To play this game in the terminal, type 'node JavaScript/script.js'

const guessTheNumber  = (num) => {
    let randomNumber = Math.floor(Math.random() * 11);

    if (randomNumber === num) {
        console.log('You Got it!');
    } else {
        console.log('Try Again');
    }
}

guessTheNumber(7);