const int trigPin = 6;
const int echoPin = 7;
const int WhiteLed = 11;
const int BlueLed = 12;
const int GreenLed = 13;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT); 
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  unsigned long duracao = pulseIn(echoPin, HIGH);
  int distancia = duracao / 58;

  if (distancia > 300){
     distancia = 300;  
  }
  
  if (distancia <= 100){
     digitalWrite(WhiteLed, HIGH);   
     digitalWrite(GreenLed, LOW);
     digitalWrite(BlueLed, LOW);
  }

  if ((distancia <= 200.00) && (distancia > 100)){
    digitalWrite(BlueLed, HIGH);   
    digitalWrite(WhiteLed, LOW);
    digitalWrite(GreenLed, LOW);
  }

  if (distancia > 200.00){
    digitalWrite(GreenLed, HIGH);   
    digitalWrite(WhiteLed, LOW);
    digitalWrite(BlueLed, LOW);
  }
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  delay(500);
}
