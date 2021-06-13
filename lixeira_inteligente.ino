// C++ code
//
#include <Servo.h>

int distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Lê o pino da onda and retorna nos milisegundos
  return pulseIn(echoPin, HIGH);
}

Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);

}

void loop()
{
  distancia = 0.01723 * readUltrasonicDistance(7, 6);

  if (distancia <= 50) {
    servo_9.write(90);
    delay(5000); // Espera por 5000 milisegundos
    servo_9.write(0);
  }
}