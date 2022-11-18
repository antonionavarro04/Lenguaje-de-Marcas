const version = "v1.0";
const state = "beta";

console.info("Version: " + version);

// ! Importaciones de Variables de HTML
var htmlV = document.getElementById("version");
var htmlS = document.getElementById("state");

// ? Solo lo imprimiremos si el estado es diferente a la release
if (state != "stable" && state != "Stable") {
    console.info("State: " + state);

    // ! Imprimimos en HTML
    htmlV.innerHTML = version;
    htmlS.innerHTML = state;

    switch (state) {
        case "pre-alpha":
            htmlS.style.color = "#990000";
            console.error("This version is a pre-alpha, it may contain errors, missing content and is not recommended to use it.");
            break;
        case "alpha":
            htmlS.style.color = "red";
            console.warn("This phase is not stable yet, it may have errors.");
            break;
        case "beta":
            htmlS.style.color = "blue";
            console.warn("This phase is not stable yet, it may have errors.");
            break;
        case "release":
            htmlS.style.color = "green";
            console.warn("This phase is nearly stable but it may have some errors.");
            break;
        case "stable":
            htmlS.remove();
            break;
        default:
            htmlS.style.color = "orange";
            htmlS.innerHTML = state + "?";
            console.error("Esta versión no tiene un estado establecido.");
            break;
    }

} else {
    // ! Imprimimos en HTML
    htmlV.innerHTML = version;
}

console.log("");

console.info("Autor: Antonio Navarro");
console.info("Github: https://github.com/antonionavarro04");
console.info("Youtube: https://www.youtube.com/c/navarro41yt");