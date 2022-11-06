// ^ Declaramos las variables horas, minutos y segundos.
var horas = 0;
var minutos = 0;
var segundos = 0;

// ^ Conseguimos una fecha completa
var fecha = new Date();

// ^ Conseguimos cada uno de los valores de la fecha
horas = fecha.getHours();
minutos = fecha.getMinutes();
segundos = fecha.getSeconds();

// ^ Mostramos la fecha en la consola
console.log(horas + ":" + minutos + ":" + segundos);

// ! Coguemos el elemento con el id content
var content = document.getElementById("content");

// ! Sobreescribimos el contenido del elemento
content.innerHTML = horas + ":" + minutos + ":" + segundos;

// ! Actualizamos la hora cada segundo
setInterval(function() {
    // ^ Conseguimos una fecha completa
    var fecha = new Date();

    // ^ Conseguimos cada uno de los valores de la fecha
    horas = fecha.getHours();
    minutos = fecha.getMinutes();
    segundos = fecha.getSeconds();

    // ! Sobreescribimos el contenido del elemento, en caso de que las horas minutos o segundos sean menor a 10, le añadimos un 0 delante
    content.innerHTML = (horas < 10 ? "0" + horas : horas) + ":" + (minutos < 10 ? "0" + minutos : minutos) + ":" + (segundos < 10 ? "0" + segundos : segundos);
} , 1000);