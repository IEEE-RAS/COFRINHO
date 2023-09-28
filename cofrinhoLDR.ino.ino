

#include <EEPROM.h>

//const int ldrPin = A0; // Pino analógico conectado ao LDR
int valorAcumuladoEndereco = 0; // Endereço na EEPROM onde o valor acumulado é armazenado

float valorAcumulado = 0.0; // Valor acumulado em ponto flutuante

void setup(){
  Serial.begin(9600);
  // Carrega o valor acumulado da EEPROM ao iniciar
  EEPROM.get(valorAcumuladoEndereco, valorAcumulado);
}

void loop() {
  int LDR_10C = analogRead(A0);
  int LDR_5C = analogRead(A1);  
  int LDR_50C = analogRead(A2);
  int LDR_25C = analogRead(A3);
  int LDR_1R = analogRead(A4);
  
  Serial.print(LDR_10C);
  Serial.print(" ");
  Serial.print(LDR_5C);
  Serial.print(" ");
  Serial.print(LDR_50C);
  Serial.print(" ");
  Serial.print(LDR_25C);
  Serial.print(" ");
  Serial.print(LDR_1R);
  Serial.println(" ");
  
  delay(500);
  
  int LDR_10C2 = analogRead(A0);
  int LDR_5C2 = analogRead(A1);  
  int LDR_50C2 = analogRead(A2);
  int LDR_25C2 = analogRead(A3);
  int LDR_1R2 = analogRead(A4);
  
  if (LDR_10C != LDR_10C2 ) {
    valorAcumulado += 0.1; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
  }
  
  if (LDR_5C != LDR_5C2 ) {
    valorAcumulado += 0.05; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
  }
  
  if (LDR_50C != LDR_50C2 ) {
    valorAcumulado += 0.5; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
  }
  
  if (LDR_25C != LDR_25C2 ) {
    valorAcumulado += 0.25; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
  }
  
  if (LDR_1R != LDR_1R2 ) {
    valorAcumulado += 1; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
  }
  
  
  Serial.print("Dinheiro no Cofre: ");
  Serial.println(valorAcumulado, 2);
  
 
}
