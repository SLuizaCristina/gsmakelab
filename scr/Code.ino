#include <Servo.h>

Servo servoBase;
Servo servoGarra;

int posBase = 90;
int posGarra = 90;

void setup() {
  Serial.begin(9600);

  servoBase.attach(9);
  servoGarra.attach(10);

  pinMode(7, OUTPUT);

  servoBase.write(posBase);
  servoGarra.write(posGarra);

  Serial.println("=== CONTROLE DO BRACO ===");
  Serial.println("U - Subir");
  Serial.println("D - Descer");
  Serial.println("O - Abrir garra");
  Serial.println("C - Fechar garra");
}

void loop() {

  if (Serial.available()) {

    char comando = Serial.read();

    if (comando == '\n' || comando == '\r') {
      return;
    }

    comando = toupper(comando); // aceita maiúsculo/minúsculo

    switch (comando) {

      case 'U': // subir
        posBase += 20;
        posBase = constrain(posBase, 0, 180);
        servoBase.write(posBase);
        Serial.println("Subindo...");
        break;

      case 'D': // descer
        posBase -= 20;
        posBase = constrain(posBase, 0, 180);
        servoBase.write(posBase);
        Serial.println("Descendo...");
        break;

      case 'O': // abrir garra
        posGarra += 20;
        posGarra = constrain(posGarra, 0, 180);
        servoGarra.write(posGarra);
        Serial.println("Abrindo garra...");
        break;

      case 'C': // fechar garra
        posGarra -= 20;
        posGarra = constrain(posGarra, 0, 180);
        servoGarra.write(posGarra);
        Serial.println("Fechando garra...");
        break;

      default:
        Serial.println("Comando invalido!");
        break;
    }

    // LED pisca ao executar comando
    digitalWrite(7, HIGH);
    delay(200);
    digitalWrite(7, LOW);
  }
}
