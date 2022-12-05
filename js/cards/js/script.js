// Importamos la libreria anime.js
import anime from './anime.es.js';

let actionTrigger = document.getElementById("action");
let card1 = document.getElementById("card1");
let card2 = document.getElementById("card2");
let card3 = document.getElementById("card3");

var animation = anime({
    targets: card1,
    translateX: 250,
    backgroundColor: "#F11",
    easing: "linear",
    duration: 3000,
    loop: true,
});

// Hacemos que al clickar actionTrigegr

actionTrigger.addEventListener("click", function () {
    animation.restart();
});