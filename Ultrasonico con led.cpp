int leer;
int amarillo=2;
int verde=3;
int rojo=4;

//Sensor de distancia donde la cercania prende más luces por Agustin Urribari//
long cm = 0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds *0.01723
  return (pulseIn(echoPin, HIGH)*0.01723);

}

void setup()
{
  Serial.begin(9600);

 pinMode(rojo,OUTPUT);
 pinMode(verde,OUTPUT);
 pinMode(amarillo,OUTPUT);
}

void loop()
{
  cm =readUltrasonicDistance(7, 6);     //Aqui determinamos la distancia para que las luces se prendan//

  Serial.print(cm);
  Serial.println("cm");
  
  if(cm<6){
 {
    digitalWrite(amarillo, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(rojo, LOW);
  }
  }
  if (cm >=7  && cm <= 11) {
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, HIGH);
    digitalWrite(rojo, LOW);
  }
 if(cm > 22) {
    digitalWrite(amarillo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(rojo, HIGH);
  }
}
  
