#include <Servo.h>

// Criação dos objetos servo para controlar os dedos
Servo dedoPolegar;   // Dedo D6
Servo dedoIndicador; // Dedo D5
Servo dedoMedio;     // Dedo D4
Servo dedoAnelar;    // Dedo D3
Servo dedoMindinho;  // Dedo D2

// Pinos dos potenciômetros
const int potPolegar = A0;   // Potenciômetro para o Dedo Polegar (D6)
const int potIndicador = A1; // Potenciômetro para o Dedo Indicador (D5)
const int potMedio = A2;     // Potenciômetro para o Dedo Médio (D4)
const int potAnelar = A3;    // Potenciômetro para o Dedo Anelar (D3)
const int potMindinho = A4;  // Potenciômetro para o Dedo Mindinho (D2)

// Pinos dos servos
const int pinDedoPolegar = 6;  // Pino do servo Dedo Polegar
const int pinDedoIndicador = 5; // Pino do servo Dedo Indicador
const int pinDedoMedio = 4;     // Pino do servo Dedo Médio
const int pinDedoAnelar = 3;    // Pino do servo Dedo Anelar
const int pinDedoMindinho = 2;  // Pino do servo Dedo Mindinho

void setup() {
  // Conectar os servos aos pinos correspondentes
  dedoPolegar.attach(pinDedoPolegar);
  dedoIndicador.attach(pinDedoIndicador);
  dedoMedio.attach(pinDedoMedio);
  dedoAnelar.attach(pinDedoAnelar);
  dedoMindinho.attach(pinDedoMindinho);
}

void loop() {
  // Ler o valor dos potenciômetros
  int valPolegar = analogRead(potPolegar);   // Valor do potenciômetro do Dedo Polegar
  int valIndicador = analogRead(potIndicador); // Valor do potenciômetro do Dedo Indicador
  int valMedio = analogRead(potMedio);         // Valor do potenciômetro do Dedo Médio
  int valAnelar = analogRead(potAnelar);       // Valor do potenciômetro do Dedo Anelar
  int valMindinho = analogRead(potMindinho);   // Valor do potenciômetro do Dedo Mindinho

  // Garantir que os valores dos potenciômetros estejam no intervalo adequado
  valPolegar = constrain(valPolegar, 100, 200);  // Dedo Polegar entre 100 e 200
  valIndicador = constrain(valIndicador, 40, 200); // Dedo Indicador entre 40 e 200
  valMedio = constrain(valMedio, 40, 200);         // Dedo Médio entre 40 e 200
  valAnelar = constrain(valAnelar, 40, 200);       // Dedo Anelar entre 40 e 200
  valMindinho = constrain(valMindinho, 40, 200);   // Dedo Mindinho entre 40 e 200

  // Mapear os valores dos potenciômetros para as posições dos servos
  int posPolegar = map(valPolegar, 100, 200, 0, 130); // Dedo Polegar limitado a 130°
  int posIndicador = map(valIndicador, 40, 200, 0, 180); // Dedo Indicador
  int posMedio = map(valMedio, 40, 200, 0, 180);       // Dedo Médio
  int posAnelar = map(valAnelar, 40, 200, 0, 180);     // Dedo Anelar
  int posMindinho = map(valMindinho, 40, 200, 0, 180); // Dedo Mindinho

  // Controlar os servos com os valores mapeados
  dedoPolegar.write(posPolegar);   // Mover Dedo Polegar
  dedoIndicador.write(posIndicador); // Mover Dedo Indicador
  dedoMedio.write(posMedio);         // Mover Dedo Médio
  dedoAnelar.write(posAnelar);       // Mover Dedo Anelar
  dedoMindinho.write(posMindinho);   // Mover Dedo Mindinho

  // Pequena pausa para estabilidade
  delay(15);
}
