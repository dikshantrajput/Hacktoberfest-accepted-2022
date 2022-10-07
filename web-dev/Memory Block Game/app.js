const game = document.querySelector(".game-container")
const newGameButton = document.querySelector(".new")
const block = document.querySelector(".game-block")
const movesText = document.querySelector(".moves")

const picArray = ["alien", "control", "planet", "robot", "satellite", "shuttle", "ufo", "weapon", "alien", "control", "planet", "robot", "satellite", "shuttle", "ufo", "weapon"]
var selected = []
var moves = 0

function shuffle(array) {
    for (var i = array.length - 1; i > 0; i--) {
        var j = Math.floor(Math.random() * (i + 1));
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    return array
}

function newGame() {
    moves = 0
    movesText.textContent = `Total Moves : ${moves}`

    game.innerHTML = ``
    const arr = shuffle(picArray)
    for (let i = 0; i < 16; i++) {
        game.innerHTML += `<div onclick="select(this)" class="bg-blue-200 h-24 w-24 rounded-md game-block off not" data-object="${arr[i]}">
            <img src="./assets/${arr[i]}.png" class="p-5"/>
        </div>`
    }
}

function select(object) {
    var f1 = 0
    var f2 = 0
    for (let i = 0; i < object.classList.length; i++) {
        if (object.classList[i] == "not") {
            f1 = 1
            break
        }
    }
    for (let i = 0; i < object.classList.length; i++) {
        if (object.classList[i] == "off") {
            f2 = 1
            break
        }
    }
    if (f1 == 0 || f2 == 0) {
        return
    }
    else {
        moves++;
        movesText.textContent = `Total Moves : ${moves}`
        object.classList.remove("off")
        object.classList.add("on")
        selected.push(object)
        if (selected.length == 2) {
            if (selected[0].getAttribute("data-object") == selected[1].getAttribute("data-object")) {
                selected[0].classList.remove("not")
                selected[1].classList.remove("not")
            }
            else {
                selected[0].classList.remove("on")
                selected[0].classList.add("off")
                selected[1].classList.remove("on")
                selected[1].classList.add("off")
            }
            selected = []
        }
    }
}

newGame()
newGameButton.addEventListener("click", newGame)
