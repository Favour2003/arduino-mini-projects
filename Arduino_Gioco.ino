#define ledRGBRED 2
#define ledRGBGREEN 4
#define ledRGBBLUE 5
#define buttonPin 7
#define ledRed 8
#define ledGreen 9
#define ledYellow 10
#define ledBlue 11
#define ledWhite 12

int buttonState = 0;
int currColor = 0;
int ledState1 = 0;
int ledState2 = 0;
int ledState3 = 0;
int ledState4 = 0;
int ledState5 = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledRGBRED, OUTPUT);
  pinMode(ledRGBGREEN, OUTPUT);
  pinMode(ledRGBBLUE, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledWhite, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  ledState1 = digitalRead(ledRed);
  ledState2 = digitalRead(ledBlue);
  ledState3 = digitalRead(ledYellow);
  ledState4 = digitalRead(ledGreen);
  ledState5 = digitalRead(ledWhite);
  currColor++;
  if (currColor > 5) {
    currColor = 1;
  }

  if (buttonState == 1) {
    if (ledState1 == 1 || ledState5 == 1) {
      ledRGB(1, 0, 0);
      Serial.println("Hai perso.");
      delay(1500);
      ledRGB(0, 0, 0);
    } else if (ledState2 == 1 || ledState4 == 1) {
      ledRGB(1, 1, 0);
      Serial.println("Vicino.");
      delay(1500);
      ledRGB(0, 0, 0);
    } else if (ledState3 == 1) {
      ledRGB(0, 1, 0);
      Serial.println("Hai vinto!!");
      vincita();
      currLed(6);
      delay(1000);
      currColor = 1;

    }
  }

  currLed(currColor);
  delay(500);

}

void ledRGB(int R, int G, int B) {

  if (R == 0) {
    digitalWrite(ledRGBRED, LOW);
  }
  else {
    digitalWrite(ledRGBRED, HIGH);
  }

  if (G == 0) {
    digitalWrite(ledRGBGREEN, LOW);
  }
  else {
    digitalWrite(ledRGBGREEN, HIGH);
  }

  if (B == 0) {
    digitalWrite(ledRGBBLUE, LOW);
  }
  else {
    digitalWrite(ledRGBBLUE, HIGH);
  }

}

void currLed(int cC) {
  switch (cC) {
    case 1: digitalWrite(ledWhite, HIGH);
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, LOW);
      break;
    case 2: digitalWrite(ledBlue, HIGH);
      digitalWrite(ledWhite, LOW);
      break;
    case 3: digitalWrite(ledYellow, HIGH);
      digitalWrite(ledBlue, LOW);
      break;
    case 4: digitalWrite(ledGreen, HIGH);
      digitalWrite(ledYellow, LOW);
      break;
    case 5: digitalWrite(ledRed, HIGH);
      digitalWrite(ledGreen, LOW);
      break;
    case 6: digitalWrite(ledWhite, LOW);
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, LOW);
      digitalWrite(ledYellow, LOW);
      ledRGB(0, 0, 0);

    default: break;
  }
}

void vincita() {
  for (int i = 0; i < 50; i++) {
    currColor++;
    if (currColor > 5) {
      currColor = 1;
    }

    currLed(currColor);
    delay(50);

  }

}
