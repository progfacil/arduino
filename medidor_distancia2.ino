#include <Ultrasonic.h>   //Carrega a biblioteca Ultrasonic  
#define tempo 500   
int frequencia = 2000;   
int atraso = 1000;  
   
//Define o pino do Arduino a ser utilizado com o pino Trigger do sensor  
#define PINO_TRIGGER 6   
//Define o pino do Arduino a ser utilizado com o pino Echo do sensor  
#define PINO_ECHO   7   
//Declaração das constantes referentes aos pinos digitais.
const int ledVerde = 13;
const int ledAmarelo = 12;
const int ledVermelho = 11;
   
//Inicializa o sensor ultrasonico  
Ultrasonic ultrasonic(PINO_TRIGGER, PINO_ECHO);   
   
void setup()  
{  
  Serial.begin(9600); //Inicializa a serial  
  pinMode(ledVerde,OUTPUT); //13 como de saída.
  pinMode(ledAmarelo,OUTPUT); //12 como de saída.
  pinMode(ledVermelho,OUTPUT); //11 como de saída.
}  
   
void loop()  
{  
  //Apagando todos os leds
  digitalWrite(ledVerde,HIGH);  
  digitalWrite(ledAmarelo,HIGH);
  digitalWrite(ledVermelho,HIGH);
  
  float cmMsec, inMsec;  
    
  //Le os dados do sensor, com o tempo de retorno do sinal  
  long microsec = ultrasonic.timing();   
   
  //Calcula a distancia em centimetros  
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);   
  
  Serial.print("cmMsec");
  Serial.print(cmMsec);  
  
  //Ajusta o atraso de acordo com a distancia  
  if (cmMsec > 80)  
  {  
    atraso = 2000;  
    digitalWrite(ledVerde,HIGH);
  }  
  else if (cmMsec >50 && cmMsec<80)  
  {  
    atraso = 1500;  
    digitalWrite(ledAmarelo,HIGH);
  }  
  else if (cmMsec >30 && cmMsec<50)  
  {  
    atraso = 1200;  
    digitalWrite(ledVermelho,HIGH);
  }  
  else if (cmMsec > 10 && cmMsec < 30)  
  {  
    atraso = 700;  
  }  
  else if (cmMsec < 10)  
  {  
    atraso = 300;  
  }  
     
  //Apresenta os dados, em centimetros, na Serial  
  Serial.print("Cent: ");  
  Serial.print(cmMsec);  
  Serial.print(" atraso : ");  
  Serial.println(atraso);  
  delay(atraso);  
} 
