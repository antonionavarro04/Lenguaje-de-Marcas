// ! Script version de BB que se mostrará en el menú principal
const version = 'v1.6.7';
const title = "LM - Index";

var versionElement = document.getElementById('version');
console.info("Versión: " + version);
versionElement.innerHTML = version;

document.title = title;