// ! Script version de BB que se mostrará en el menú principal
let version = 'v1.6.1';

let versionElement = document.getElementById('version');
console.info("Versión: " + version);
versionElement.innerHTML = version;