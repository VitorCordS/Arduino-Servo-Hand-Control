#include <Servo.h>

// Criação dos objetos servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Pinos dos potenciômetros
int pot1 = A0;  // A0 controla o D6
int pot2 = A1;  // A1 controla o D5
int pot3 = A2;  // A2 controla o D4
int pot4 = A3;  // A3 controla o D3
int pot5 = A4;  // A4 controla o D2

// Pinos dos servos
int servoPin1 = 6;  // Servo 1 no pino D6 (limite de 130°)
int servoPin2 = 5;  // Servo 2 no pino D5
int servoPin3 = 4;  // Servo 3 no pino D4
int servoPin4 = 3;  // Servo 4 no pino D3
int servoPin5 = 2;  // Servo 5 no pino D2

void setup() {
  // Conectar os servos aos pinos
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
}

void loop() {
  // Ler o valor dos potenciômetros
  int val1 = analogRead(pot1);  // A0
  int val2 = analogRead(pot2);  // A1
  int val3 = analogRead(pot3);  // A2
  int val4 = analogRead(pot4);  // A3
  int val5 = analogRead(pot5);  // A4

  // Garantir que os valores dos potenciômetros estejam no intervalo adequado
  val1 = constrain(val1, 100, 200);  // A0 entre 100 e 200
  val2 = constrain(val2, 40, 200);   // A1 entre 40 e 200
  val3 = constrain(val3, 40, 200);   // A2 entre 40 e 200
  val4 = constrain(val4, 40, 200);   // A3 entre 40 e 200
  val5 = constrain(val5, 40, 200);   // A4 entre 40 e 200

  // Mapear o potenciômetro A0 (100 a 200) para o intervalo de 0 a 130 (servo D6)
  int servo1Pos = map(val1, 100, 200, 0, 130);  // D6 vai até 130°

  // Mapear os outros potenciômetros (40 a 200) para o intervalo de 0 a 180
  int servo2Pos = map(val2, 40, 200, 0, 180);  // D5
  int servo3Pos = map(val3, 40, 200, 0, 180);  // D4
  int servo4Pos = map(val4, 40, 200, 0, 180);  // D3
  int servo5Pos = map(val5, 40, 200, 0, 180);  // D2

  // Controlar os servos com os valores dos potenciômetros
  servo1.write(servo1Pos);  // Servo D6 limitado a 130°
  servo2.write(servo2Pos);  // Servo D5
  servo3.write(servo3Pos);  // Servo D4
  servo4.write(servo4Pos);  // Servo D3
  servo5.write(servo5Pos);  // Servo D2

  // Pequena pausa para estabilidade
  delay(15);
}

