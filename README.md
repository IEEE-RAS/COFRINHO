# Contador de Moedas - Arduino

Este projeto consiste em um contador de moedas usando um Arduino,LEDs, LDRs (sensor de luz) e um display LCD. Ele permite que você insira diferentes moedas e acompanhe o valor acumulado em um display LCD.

Esquema eletrico no tinkecard
![image](https://github.com/IEEE-RAS/COFRINHO/assets/97792380/7fa1c818-b04e-42d5-9ad8-96a25e6b1507)
https://www.tinkercad.com/things/0SiEbaC0pgp-lcd-sem-i2c?sharecode=3_n9X8H0lwXmiTLT79irRW0Y71OyNjX-GP4S7P6LIL8

## Componentes Necessários

- Arduino Uno (ou similar)
- Display LCD 16x2
- Sensor de luz (LDR) para detectar as moedas
- LED para iluminar a área do LDR
- Botão para resetar o valor acumulado
- Resistores, fios e componentes básicos de eletrônica
- Rampa e estrutura inclinada para separar as moedas (em construção)

## Configuração do Projeto

1. Conecte o display LCD ao Arduino conforme o esquema de pinagem especificado no código.
2. Conecte o sensor de luz (LDR) aos pinos analógicos do Arduino para detectar as moedas.
3. Conecte o LED a um pino digital do Arduino para iluminar a área do LDR.
4. Conecte um botão ao Arduino para permitir o reset do valor acumulado.
5. Carregue o código fornecido neste repositório para o Arduino usando a IDE do Arduino.

## Funcionamento

- O LED é ligado para iluminar a área do LDR.
- Quando uma moeda passa entre o LED e o LDR, a luz é interrompida, e o Arduino conta essa interrupção como uma moeda cujo os valores são definidos para cada sensor.
- O display LCD mostra a mensagem inicial e o valor acumulado em dinheiro.
- Você pode inserir moedas para incrementar o valor acumulado.
- Pressione o botão conectado ao Arduino para resetar o valor acumulado.


