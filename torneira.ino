#include ThreeWire.h INCLUSÃO DA BIBLIOTECA
#include RtcDS1302.h INCLUSÃO DA BIBLIOTECA
#include Wire.h
#include Servo.h


Servo myservo;
int pos = 0;


ThreeWire myWire(3, 4, 2); OBJETO DO TIPO ThreeWire
RtcDS1302ThreeWire Rtc(myWire); OBJETO DO TIPO RtcDS1302


void setup () {
    Serial.begin(9600); INICIALIZA A SERIAL
    myservo.attach(9);
    Rtc.Begin(); INICIALIZA O RTC
    Serial.print(Compilado em ); IMPRIME O TEXTO NO MONITOR SERIAL
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__); VARIÁVEL RECEBE DATA E HORA DE COMPILAÇÃO
    printDateTime(compiled); PASSA OS PAR METROS PARA A FUNÇÃO printDateTime
    Serial.println(); QUEBRA DE LINHA NA SERIAL
    Serial.println(); QUEBRA DE LINHA NA SERIAL


    if(Rtc.GetIsWriteProtected()){ SE O RTC ESTIVER PROTEGIDO CONTRA GRAVAÇÃO, FAZ
        Serial.println(RTC está protegido contra gravação. Habilitando a gravação agora...); IMPRIME O TEXTO NO MONITOR SERIAL
        Rtc.SetIsWriteProtected(false); HABILITA GRAVAÇÃO NO RTC
        Serial.println(); QUEBRA DE LINHA NA SERIAL
    }


    if(!Rtc.GetIsRunning()){ SE RTC NÃO ESTIVER SENDO EXECUTADO, FAZ
        Serial.println(RTC não está funcionando de forma contínua. Iniciando agora...); IMPRIME O TEXTO NO MONITOR SERIAL
        Rtc.SetIsRunning(true); INICIALIZA O RTC
        Serial.println(); QUEBRA DE LINHA NA SERIAL
    }


    RtcDateTime now = Rtc.GetDateTime(); VARIÁVEL RECEBE INFORMAÇÕES
    if (now  compiled) { SE A INFORMAÇÃO REGISTRADA FOR MENOR QUE A INFORMAÇÃO COMPILADA, FAZ
        Serial.println(As informações atuais do RTC estão desatualizadas. Atualizando informações...); IMPRIME O TEXTO NO MONITOR SERIAL
        Rtc.SetDateTime(compiled); INFORMAÇÕES COMPILADAS SUBSTITUEM AS INFORMAÇÕES ANTERIORES
        Serial.println(); QUEBRA DE LINHA NA SERIAL
    }
    else if (now  compiled){ SENÃO, SE A INFORMAÇÃO REGISTRADA FOR MAIOR QUE A INFORMAÇÃO COMPILADA, FAZ
        Serial.println(As informações atuais do RTC são mais recentes que as de compilação. Isso é o esperado.); IMPRIME O TEXTO NO MONITOR SERIAL
        Serial.println(); QUEBRA DE LINHA NA SERIAL
    }
    else if (now == compiled) { SENÃO, SE A INFORMAÇÃO REGISTRADA FOR IGUAL A INFORMAÇÃO COMPILADA, FAZ
        Serial.println(As informações atuais do RTC são iguais as de compilação! Não é o esperado, mas está tudo OK.); IMPRIME O TEXTO NO MONITOR SERIAL
        Serial.println(); QUEBRA DE LINHA NA SERIAL
    }
}


void loop () {
    RtcDateTime now = Rtc.GetDateTime(); VARIÁVEL RECEBE INFORMAÇÕES
    printDateTime(now); PASSA OS PAR METROS PARA A FUNÇÃO printDateTime
    Serial.println();
    delay(1000); INTERVALO DE 1 SEGUNDO


    if (now.Hour() == 19 & now.Minute() == 02 & now.Second() == 00) {
    Serial.println(ABRIU);
    for (pos = 180; pos = 0; pos -= 1) {  goes from 180 degrees to 0 degrees
      myservo.write(pos);               tell servo to go to position in variable 'pos'
      delay(5);
    }
  }
  if (now.Hour() == 19  & now.Minute() == 02  & now.Second() == 10){
    Serial.println(FECHOU);
    for (pos = 0; pos = 180; pos += 1) {  goes from 0 degrees to 180 degrees
       in steps of 1 degree
      myservo.write(pos);               tell servo to go to position in variable 'pos'
      delay(5);                        waits 15 ms for the servo to reach the position
    }
  }
}


#define countof(a) (sizeof(a)  sizeof(a[0]))


void printDateTime(const RtcDateTime& dt){
    char datestring[20]; VARIÁVEL ARMAZENA AS INFORMAÇÕES DE DATA E HORA


    snprintf_P(datestring,
            countof(datestring),
            PSTR(%02u%02u%04u %02u%02u%02u), FORMATO DE EXIBIÇÃO DAS INFORMAÇÕES
            dt.Day(), DIA
            dt.Month(), MÊS
            dt.Year(), ANO
            dt.Hour(), HORA
            dt.Minute(), MINUTOS
            dt.Second() ); SEGUNDOS
    Serial.print(datestring); IMPRIME NO MONITOR SERIAL AS INFORMAÇÕES
}
