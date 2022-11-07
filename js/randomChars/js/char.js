let num = 0;

// ! Declaramos un array con algunos caracteres
let chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()_+-=[]{}|;':,./<>?";

// ! Declaramos una variable que contendra el texto que se mostrara en pantalla
numJs = document.getElementById("num");

// ? Generamos un numero aleatorio entre 0 y n
let random = Math.floor(Math.random() * chars.length);

// ! Mostramos el numero aleatorio
numJs.innerHTML = chars[random];

setInterval(() => {
    // ? Generamos un numero aleatorio entre 0 y n
    let random = Math.floor(Math.random() * chars.length);

    // ! Mostramos el numero aleatorio
    numJs.innerHTML = chars[random];
}, 1000);