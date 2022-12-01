
/**
 * @author Antonio Navarro
*/

let actionTrigger = document.getElementById("action");
let card1 = document.getElementById("card1");
let card2 = document.getElementById("card2");
let card3 = document.getElementById("card3");

actionTrigger.addEventListener("click", function() {
    console.log("Action Triggered!");
    // Movemos el elemento card1 a la derecha
    card1.style.transform = "translateX(100%)";
});