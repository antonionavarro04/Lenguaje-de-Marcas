const version = "v1.3";
const state = "alpha";

console.info("Version: " + version);

// ! Importaciones de Variables de HTML
var htmlV = document.getElementById("version");
var htmlS = document.getElementById("state");

// ? Solo lo imprimiremos si el estado es diferente a la release
if (state != "stable" || state != "Stable") {
    console.info("State: " + state);

    // ! Imprimimos en HTML
    htmlV.innerHTML = version;
    htmlS.innerHTML = state;

    switch (state) {
        case "pre-alpha":
            htmlS.style.color = "#990000";
            break;
        case "alpha":
            htmlS.style.color = "red";
            break;
        case "beta":
            htmlS.style.color = "blue";
            break;
        case "release":
            htmlS.style.color = "green";
            break;
        default:
            htmlS.style.color = "black";
            break;
    }

} else {
    // ! Imprimimos en HTML
    htmlV.innerHTML = version;
}