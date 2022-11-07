// ! Script version de BB que se mostrará en el menú principal
let version = 'v1.5.5';

let versionElement = document.getElementById('version');
console.info("Versión: " + version);
versionElement.innerHTML = version;