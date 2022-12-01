// Importamos la libreria anime.js
import anime from './anime.es.js';

let actionTrigger = document.getElementById("action");
let card1 = document.getElementById("card1");
let card2 = document.getElementById("card2");
let card3 = document.getElementById("card3");

anime({
    targets: card1,
});