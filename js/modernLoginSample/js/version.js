const version = "v1.2"
const state = "alpha"

console.info("Version: " + version)

// ? Solo lo imprimiremos si el estado es diferente a la release
if (state != "release") {
    console.info("State: " + state)
}