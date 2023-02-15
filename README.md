# Projeto final Sistemas Embarcados - Sistema de Irrigação
Automação torneira utilizando arduíno e servo motor
## Objetivo
O objetivo principal do nosso projeto foi baseado em montar um sistema para ligar e desligar uma torneira sem que haja a presença do contato humano, utilizando o arduino uno, um RTC (Relógio de Tempo Real), um servo motor,  uma torneira e algumas conexões, como joelho e pedaços de cano. 

## Desenvolvimento
### Material

- Arduino - Controlar a rotação do servo motor, o que permite controlar a abertura da torneira;
- Servo Motor - Fechar e abrir a torneira, conforme o tempo que seja determinado pelo relógio em tempo real;
- RTC(Real Time Clock) - Armazenar o tempo para ligar e desligar a torneira;
- Torneira;
- Conexões de canos -  Ajudar a segurar o motor.

## Resultado

<img src="./projeto torneira.jpeg" />

## Conclusão
O resultado final foi o esperado, tendo em vista que está tudo funcionando de forma correta. O servo motor rotaciona 180 graus a torneira, que é aberta, quando a hora, minuto e segundo é chegado de forma exata. A hora é recebida por meio do RTC que é transmitida para o arduino uno e passada o comando rotação para o servo motor. O mesmo se dá ao rotacionar 180 graus de forma contrária.

# Participantes
- Adriana Euflazino da Silva
- Edson Domingos da Silva
- Jobson Frank Floriano
- Laura Kauanne da Silva
- Nayonara Galvão da Silva
- Oziele Rodrigues de Oliveira
- Professor: Bruno Augusto Vitorino
