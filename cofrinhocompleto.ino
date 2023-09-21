//#include <LiquidCrystal.h>

//Projeto 9 – Escrever uma mensagem no display LCD 16 x 2
#include <Wire.h>
#include <EEPROM.h>

//LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int backLight = 13;// pino 13 responsável pelo controle do LED
int LEDS = 8;

const int ldrPin = A0; // Pino analógico conectado ao LDR
int valorAcumuladoEndereco = 0; // Endereço na EEPROM onde o valor acumulado é armazenado

float valorAcumulado = 0.0; // Valor acumulado em ponto flutuante


void setup(){
  
  EEPROM.get(valorAcumuladoEndereco, valorAcumulado);// Carrega o valor acumulado da EEPROM ao iniciar
  
  pinMode(LEDS,OUTPUT);
  digitalWrite(LEDS, HIGH);
  //pinMode(backLight, OUTPUT);
  //digitalWrite(backLight, HIGH);// Liga backlight. Substituir 'HIGH' por 'LOW' para desligar a luz de fundo.

  lcd.begin(16, 2);//Colunas, linhas. Use 16,2 para display LCD 16x2
  lcd.clear();// Inicializa o display com uma tela vazia
  lcd.setCursor(0, 0);//Posiciona o cursor na coluna 0, linha 0 (primeira linha)
  lcd.print("RAS - PROJETO");//Escreve o texto desejado

  lcd.setCursor(6, 1);//Posiciona o cursor para a coluna 0, linha 1 (segunda linha)
  lcd.print("COFRINHO");
  delay(1000);
  lcd.clear();
  
  Serial.begin(9600);//Inicializa a comunicação serial em 9600 bits por segundo
}

void loop() {
  int LDR_10C = analogRead(A0);
  int LDR_5C = analogRead(A1);  
  int LDR_50C = analogRead(A2);
  int LDR_25C = analogRead(A3);
  int LDR_1R = analogRead(A4);

  
  
  
  if (LDR_10C < 500) {
    valorAcumulado += 0.1; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
    
  }
  if (LDR_5C < 500){
    valorAcumulado += 0.05; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
    
  }
  if (LDR_50C < 500) {
    valorAcumulado += 0.5; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
    
  }
  
  if (LDR_25C < 500){
    valorAcumulado += 0.25; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
    
  }
  
  if (LDR_1R < 500){
    valorAcumulado += 1.0; // Adiciona 0.5 ao valor acumulado
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado); // Armazena o valor acumulado na EEPROM
    
  }
  
  lcd.setCursor(0,0);
  lcd.print("Dinheiro:");
  lcd.setCursor(2,1);
  lcd.print(valorAcumulado);
  delay(200);
  
  
}
