var num = 0;
const delay = 500; // ? ms

// ! Declaramos un array con algunos caracteres
const chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]{}|;':,./<>?ºª€¬¿¡あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをんアイウエオカキクケコサシスセソタチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワヲン川曼殊沙華ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõöøùúûüýþÿБВГДЖЗИЙЛПФЦЧШЩЪЫЬЭЮЯбвгджзийлпфцчшщъыьэюя";

// ! Declaramos una variable que contendra el texto que se mostrara en pantalla
numJs = document.getElementById("num");

// ? Generamos un numero aleatorio entre 0 y n
var random = Math.floor(Math.random() * chars.length);

// ! Mostramos el numero aleatorio
numJs.innerHTML = chars[random];

// ! Sacamos el titulo actual del documento
title = document.title;

// ! Actualizamos el titulo con el numero
document.title = title + " - [ " + chars[random] + " ]";

setInterval(() => {
    // ? Generamos un numero aleatorio entre 0 y n
    random = Math.floor(Math.random() * chars.length);

    // ! Mostramos el numero aleatorio
    numJs.innerHTML = chars[random];

    // ! Actualizamos el titulo con el numero
    document.title = title + " - [ " + chars[random] + " ]";
}, delay);