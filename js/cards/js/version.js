
/**
 * @author Antonio Navarro
*/

// ^ Definimos variables
const version = "v1.0";
const state = "Alpha";

// ^ Importaciones de Variables de HTML
var htmlV = document.getElementById("version");
var htmlS = document.getElementById("state");

// ! Imprimimos la Versión y el Estado
console.info("Version: " + version);
console.info("State: " + state);

// ! Imprimimos en HTML la Versión y el Estado
htmlV.innerHTML = version;
htmlS.innerHTML = state;

// ! Imprimiremos un mensaje extra en la consola según el State y el color cambiara segun el State, si es Stable se ocultaran las versiones del Documento
switch (state) {
    case "Pre-Alpha":
        htmlS.style.color = "#990000";
        htmlV.style.color = "#990000";
        console.error("This version is a pre-alpha, it may contain errors, missing content and is not recommended to use it.");
        break;
    case "Alpha":
        htmlS.style.color = "red";
        htmlV.style.color = "red";
        console.warn("This phase isn't stable yet, it may have errors.");
        break;
    case "Beta":
        htmlS.style.color = "blue";
        htmlV.style.color = "blue";
        console.warn("This phase isn't stable yet, it may have some errors.");
        break;
    case "Release":
        htmlS.style.color = "#00BB00";
        htmlV.style.color = "#00BB00";
        console.warn("This phase is nearly stable but it may have small errors.");
        break;
    case "Stable":
        htmlV.remove();
        htmlS.remove();
        break;
    default:
        htmlS.style.color = "orange";
        htmlV.style.color = "orange";
        htmlS.innerHTML = state + "?";
        console.error("This version doesn't have a established state. It may be an error.");
        break;
}

console.log("");

// ^ Informaciones Extra y Spam
console.error("Author: Antonio Navarro");
console.error("Youtube: https://www.youtube.com/c/navarro41yt");
console.error("Github: https://github.com/antonionavarro04");