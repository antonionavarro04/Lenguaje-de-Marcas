
// ^ Definimos los dos archivos de Audio
var rollAudio = document.getElementById('rollAudio');
var coverAudio = document.getElementById('coverAudio');

// ^ Cogemos los botones 1 y 2 del HTML
var button1 = document.getElementById("button1");
var button2 = document.getElementById("button2");

// ^ Cogemos los divs con id dice1 y dice2 del HTML
var dice1 = document.getElementById("dice1");
var dice2 = document.getElementById("dice2");

// ^ Numeros dado1 y dado2 como un array de enteros de 2 posiciones al igual que los valores
var dado = [6, 6];
var values = ["", ""];

// ^ Estado de si esta tapado o no
var covered = true;

// ? Hacemos que al hacer click en el botón 1 se ejecute la función "roll"
// Con un cooldown de 3 segundos
    button1.addEventListener("click", roll);

// ? Hacemos que al hacer click en el botón 2 se ejecute la función "tapar"
button2.addEventListener("click", cover);

// Creamos la funcion "roll"
function roll() {
    // Reproducimos el Audio roll
    rollAudio.play();

    // Generamos dos numeros aleatorios entre 0 y 5 y los guardamos en el array
    for (let i = 0; i < dado.length; i++) {
        dado[i] = Math.floor(Math.random() * 6);

        // Procesamos los valores de los dados
        process(i);
    }

    // Imprimimos a modo de info los datos por consola
    console.info("Dado 1: " + dado[0]);
    console.info("Dado 2: " + dado[1]);

    // Salto de linea para la consola
    console.log("");

    // Cambiamos el texto del dado1 y dado2
    dice1.innerHTML = values[0];
    dice2.innerHTML = values[1];

    // Cambiamos el estado de tapado a false
    covered = false;
}

// Creamos la funcion "cover"
function cover() {
    // Reproducimos el Audio cover
    coverAudio.play();

    if (covered) {
        for (let i = 0; i < dado.length; i++) {
            // Procesamos los valores de los dados
            process(i);
        }
        dice1.innerHTML = values[0];
        dice2.innerHTML = values[1];
        covered = false;
    } else {
        dice1.innerHTML = "?";
        dice2.innerHTML = "?";
        dice1.style.color = "black";
        dice2.style.color = "black";
        covered = true;
    }
}

function process(i) {
    // ! Procesamos tanto dado[0] como dado[1]
    switch (dado[i]) {
        case 0:
            values[i] = "...";
            break;

        case 1:
            values[i] = "....";
            break;

        case 2:
            values[i] = "J";
            break;

        case 3:
            values[i] = "Q";
            break;

        case 4:
            values[i] = "K";
            break;

        case 5:
            values[i] = "⬤";
            break;

        case 6:
            values[i] = "?";
            break;

        default:
            break;
    }

    // ? Color
    if (values[i] == "J" || values[i] == "Q" || values[i] == "...") {
        if (i == 0) {
            dice1.style.color = "black";
        } else {
            dice2.style.color = "black";
        }
    } else {
        if (i == 0) {
            dice1.style.color = "red";
        } else {
            dice2.style.color = "red";
        }
    }
}

init();
