// Script que blinkee el led de la placa arduino
// Autor: Ing. Jorge Luis Mayorga Taborda
// Fecha: 2019-08-20
// Versión: 1.0
// Licencia: GPL v3

// Incluye la librería para el manejo de los pines de la placa arduino
#include <Arduino.h>

#define LED 13

// Función de configuración
void setup() {
  // Inicializa el pin 13 como salida
  pinMode(LED, OUTPUT);
}