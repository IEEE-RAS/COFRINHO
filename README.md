# Contador de Moedas - Arduino.

Este projeto consiste em um contador de moedas usando um Arduino, LEDs, LDRs (sensor de luz) e um display LCD. Ele permite que você insira diferentes moedas e acompanhe o valor acumulado em um display LCD.
A estrutura promove inserção de moedas, que pela força da gravidade deslizam sobre uma rampa inclinada, desenhada com cortes que promovem a seleção das moedas mediante os diâmetros específicos das moedas de 0,05/0,10/0,25 centavos e R$ 1,00.

Esquema de montagem:

![image](https://github.com/IEEE-RAS/COFRINHO/assets/97792380/5e79e7c3-0970-4d03-8d9c-aa846c30e662)
https://www.tinkercad.com/things/0SiEbaC0pgp-lcd-sem-i2c?sharecode=3_n9X8H0lwXmiTLT79irRW0Y71OyNjX-GP4S7P6LIL8

Esquema de montagem atualizado: 

ATUALIZADO 29-08
https://www.tinkercad.com/things/lFlIIqTEBOB-copy-of-lcd-sem-i2c/editel?tenant=circuits


## Componentes Utilizados neste projeto

- Arduino Uno (ou similar)
- Display LCD 16x2
- 5x Sensor de luz (LDR) para detectar as moedas
- 5x LED para iluminar a área do LDR
- 1x Botão para resetar o valor acumulado de dinheiro
- Resistores, fios e componentes básicos de eletrônica
- Pack de 3x baterias auxiliares
- Rampa desenhada com impresssora 3D (Imagem 01) e estrutura divisória, inclinada de acrílico(em construção) para separar as moedas
  -imagem dos componentes-

## Configuração do Projeto

1. Conecte o display LCD ao Arduino conforme o esquema de pinagem especificado no código.
2. Conecte o sensor de luz (LDR) aos pinos analógicos do Arduino para detectar as moedas.
3. Conecte o LED a um pino digital do Arduino para iluminar a área do LDR.
4. Conecte um botão ao Arduino para permitir o reset do valor acumulado.
5. Carregue o código fornecido neste repositório para o Arduino usando a IDE do Arduino.

## Funcionamento

- O LED é ligado para iluminar à direção ao LDR(Light Dependent Resistor, ou Resistor Dependente de Luz). Componente eletrônico cuja resistência elétrica varia de acordo com a luminosidade que incide sobre ele.
- Quando uma moeda passa entre o LED e o LDR, a luz é interrompida, e o Arduino conta essa interrupção como uma moeda cujo os valores são definidos para cada sensor.
- O display LCD mostra a mensagem inicial e o valor acumulado em dinheiro.
- Você pode inserir moedas para incrementar o valor acumulado.
- Pressione o botão conectado ao Arduino para resetar o valor acumulado.

## Detalhes da estrutura
- A estrutura que apoia a rampa possui duas inclinações: uma para deslizamento da moeda e outra para apoiá-la à rampa e melhor guiá-la.
- O compartimento de passagem/queda de cada moeda(após seleção da rampa) é isolado dos demais, que internamente conta com um conjunto LED - LDR, apontados e posicionados na mesma direção.
 -imagem da estrutura-
  
## Versões

Versão anterior sem botão de reset: https://www.tinkercad.com/things/lFlIIqTEBOB-copy-of-lcd-sem-i2c/editel?tenant=circuits

## GIF de funcionamento do cofrinho (final do projeto)

