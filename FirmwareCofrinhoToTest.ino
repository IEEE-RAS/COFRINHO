#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int backLight = 13;
int LEDS = 8;

const int ldrPin = A0;
int valorAcumuladoEndereco = 0;

float valorAcumulado = 0.0;

bool botaoPressionado = false;
const int botaoPin = 7; // Pino para o botão

void setup() {
  pinMode(LEDS, OUTPUT);
  digitalWrite(LEDS, HIGH);
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RAS - PROJETO");
  lcd.setCursor(6, 1);
  lcd.print("COFRINHO");
  delay(1000);
  lcd.clear();

  Serial.begin(9600);

  // Inicializa o botão como entrada
  pinMode(botaoPin, INPUT);

  // Lê o valor acumulado da EEPROM
  EEPROM.get(valorAcumuladoEndereco, valorAcumulado);
}

void loop() {
  // Verifica se o botão foi pressionado
  if (digitalRead(botaoPin) == HIGH) {
    botaoPressionado = true;
    delay(50); // Delay para evitar leituras falsas devido a bouncing do botão
  }

  if (botaoPressionado) {
    // Se o botão foi pressionado, resete o valor acumulado e salve na EEPROM
    valorAcumulado = 0.0;
    EEPROM.put(valorAcumuladoEndereco, valorAcumulado);
    botaoPressionado = false; // Reseta a flag do botão
  }

  // Leia os valores dos LDRs
  int LDR_10C = analogRead(A0);
  int LDR_5C = analogRead(A1);
  int LDR_50C = analogRead(A2);
  int LDR_25C = analogRead(A3);
  int LDR_1R = analogRead(A4);

  // Atualize o valor acumulado com base nos LDRs
  
  if (LDR_25C < 250){
    valorAcumulado += 0.25;
  }
  

  // Escreva o valor acumulado na EEPROM
  EEPROM.put(valorAcumuladoEndereco, valorAcumulado);

  // Atualize o display LCD com o valor acumulado
  lcd.setCursor(0, 0);
  lcd.print("Dinheiro:");
  lcd.setCursor(2, 1);
  lcd.print(valorAcumulado);
  lcd.setCursor(11, 1);
  lcd.print(LDR_25C);
  delay(200);
}
