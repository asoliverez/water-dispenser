#include <LiquidCrystal.h>
#include <FlowSensor.h>

#define typeFlow YFS201

// Definición de pines
const int fichaPin = 7;
const int pulsador1Pin = 0;
const int pulsador2Pin = 1;
const int electrovalvula1Pin = 8;
const int electrovalvula2Pin = 9;
const int sensorFlujoPin = 6;

// Inicialización del display LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(11, 12, 2, 3, 4, 5);

// Inicialización del sensor de flujo
FlowSensor flowSensor(typeFlow, sensorFlujoPin);

// Variables para almacenar el estado de los pines
int fichaEstado = LOW;
int pulsador1Estado = LOW;
int pulsador2Estado = LOW;

void setup() {
  // Configuración de los pines
  pinMode(fichaPin, INPUT);
  pinMode(pulsador1Pin, INPUT);
  pinMode(pulsador2Pin, INPUT);
  pinMode(electrovalvula1Pin, OUTPUT);
  pinMode(electrovalvula2Pin, OUTPUT);
  pinMode(sensorFlujoPin, INPUT);
  
  // Inicialización del display LCD
  lcd.begin(16, 2);
  lcd.print("bienvenido");
  lcd.setCursor(0, 1);
  lcd.print("Inserte ficha");

  // Inicialización del sensor de flujo
  flowSensor.begin();
}

void loop() {
  // Leer el estado de la ficha
  fichaEstado = digitalRead(fichaPin);

  if (fichaEstado == HIGH) {
    lcd.clear();
    lcd.print("Seleccione ");
    lcd.setCursor(0, 1);
    lcd.print("Natural o Fria");

    // Esperar la selección de un pulsador
    while (pulsador1Estado == LOW && pulsador2Estado == LOW) {
      pulsador1Estado = digitalRead(pulsador1Pin);
      pulsador2Estado = digitalRead(pulsador2Pin);
    }

    lcd.clear();
    lcd.print("Coloque su");
    lcd.setCursor(0, 1);
    lcd.print("botella");
    delay(1000);

    // Activar la electrovalvula correspondiente
    if (pulsador1Estado == HIGH) {
      digitalWrite(electrovalvula1Pin, HIGH);
    } else if (pulsador2Estado == HIGH) {
      digitalWrite(electrovalvula2Pin, HIGH);
    }

    // Contar los pulsos del sensor de flujo
    int pulseCount = 0;
    while (pulseCount < 222) {
      if (digitalRead(sensorFlujoPin) == HIGH) {
        pulseCount++;
        while (digitalRead(sensorFlujoPin) == HIGH); // Esperar a que el pulso baje
      }
    }

    // Desactivar la electrovalvula
    digitalWrite(electrovalvula1Pin, LOW);
    digitalWrite(electrovalvula2Pin, LOW);

    // Mensaje de despedida
    lcd.clear();
    lcd.print("Muchas gracias");
    lcd.setCursor(0, 1);
    lcd.print("Hasta pronto");

    // Esperar un momento antes de reiniciar
    delay(2000);

    // Reiniciar los estados de los pulsadores
    pulsador1Estado = LOW;
    pulsador2Estado = LOW;

    // Mensaje de bienvenida
    lcd.clear();
    lcd.print("Bienvenido");
    lcd.setCursor(0, 1);
    lcd.print("Inserte ficha");
  }
}
