/**
 * @author Antonio Navarro
 */

// ^ Definimos variables
const version = "v1.3";
const state = "Alpha";
const title = "Kiriki"

// ^ Importaciones de Variables de HTML
var htmlV = document.getElementById("version");
var htmlS = document.getElementById("state");
var htmlT = document.getElementById("title");

// ! Imprimimos la Versión y el Estado
console.info("Title: " + title);
console.info("State: " + state);
console.info("Version: " + version);

// ! Imprimimos en HTML la Versión y el Estado
htmlV.innerHTML = version;
htmlS.innerHTML = state;
htmlT.innerHTML = title;

// ! Imprimiremos un mensaje extra en la consola según el State y el color cambiara segun el State, si es Stable se ocultaran las versiones del Documento
switch (state) {
    case "Pre-Alpha":
        htmlS.style.color = "#990000";
        htmlV.style.color = "#990000";
        htmlT.style.color = "#990000";
        console.error("This version is a pre-alpha, it may contain errors, missing content and is not recommended to use it.");
        break;
    case "Alpha":
        htmlS.style.color = "red";
        htmlV.style.color = "red";
        htmlT.style.color = "red";
        console.warn("This phase isn't stable yet, it may have errors.");
        break;
    case "Beta":
        htmlS.style.color = "blue";
        htmlV.style.color = "blue";
        htmlT.style.color = "blue";
        console.warn("This phase isn't stable yet, it may have some errors.");
        break;
    case "Release":
        htmlS.style.color = "#00BB00";
        htmlV.style.color = "#00BB00";
        htmlT.style.color = "#00BB00";
        console.warn("This phase is nearly stable but it may have small errors.");
        break;
    case "LTS":
        htmlV.remove();
        htmlS.remove();
        htmlT.remove();
        break;
    default:
        htmlS.style.color = "orange";
        htmlV.style.color = "orange";
        htmlT.style.color = "orange";
        htmlS.innerHTML = state + "?";
        console.error("This version doesn't have a established state. It may be an error.");
        break;
}

console.log("");

// ^ Informaciones Extra y Spam
console.error("Author: Antonio Navarro");
console.error("Youtube: https://www.youtube.com/c/navarro41yt");
console.error("Github: https://github.com/antonionavarro04");