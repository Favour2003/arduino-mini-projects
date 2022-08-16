#define TRIG_PIN 6
#define ECHO_PIN 7
#define ledGreen 10
#define ledYellow 9
#define ledRed 8

int delayLed = 1000;

void setup(){
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long tempo = pulseIn(ECHO_PIN, HIGH);
  float distanza = 0.03438 * tempo / 2;
  if(distanza > 30){
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
  }
  else if(distanza < 30 && distanza > 15){
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
  }
  else if(distanza <= 15 && distanza >= 4){
    delayLed = distanza * 75;
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
    lampeggio(delayLed);
    delay(100);
    Serial.println(delayLed);
    
  }
  else if(distanza < 4){
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
  }
  Serial.println("Distanza: " + String(distanza) + "cm");
  

}

void lampeggio(int d){
  digitalWrite(ledRed, LOW);
  delay(d);
  digitalWrite(ledRed, HIGH);
}
