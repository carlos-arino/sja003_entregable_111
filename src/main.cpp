/* Ejercicio entregable 011
 Deben de utilizar este archivo los alumnos con c<5, d<5, u>=5
 siendo c,d,u las tres últimas cifras del DNI 22000cdu -W
 Luminosidad y motor continua con potenciometro
 Para cambiar Luminosidad o haz click sobre el sensor NTC durante la simulacion
 rellenar vuestro nombre y DNI
 NOMBRE ALUMNO: XXXXX
 DNI: XXXXX
 ENLACE WOKWI: XXXXXXX
*/

#include <Arduino.h>

const int luxPin = 35; // Pin analógico para el sensor de luminosidad
const int potPin = 34; // Pin analógico para el sensor de posición

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  ledcAttachPin(26, 0);
  ledcSetup(0, 1000, 10); // frecuencia 1KHz y resolucion 2^10
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
  if (millis() < 5000)
    ledcWrite(0, 200);
  if (millis() > 5000)
    ledcWrite(0, 500);
  if (millis() > 10000)
    ledcWrite(0, 1000);
  Serial.print(analogRead(potPin));
  Serial.print(", ");
  Serial.print(analogRead(luxPin));
  Serial.println(" ");
  delay(100);
}