#define ledRGBRed1 3
#define ledRGBGreen1 4
#define ledRGBBlue1 5
#define ledRGBRed2 12
#define ledRGBGreen2 11
#define ledRGBBlue2 10
#define buttonPin1 2
#define buttonPin2 13
#define led1 6
#define led2 7
#define led3 8
#define led4 9

int buttonState1 = 0;
int buttonState2 = 0;
int led = 0;
int ledDirection = 1;
int ledState1 = 0;
int ledState2 = 0;
int numHP1 = 3;
int numHP2 = 3;
int defaultDelay = 1000;
int currentDelay = 1000;

void setup() {
  pinMode(ledRGBRed1, OUTPUT);
  pinMode(ledRGBGreen1, OUTPUT);
  pinMode(ledRGBBlue1, OUTPUT);
  pinMode(ledRGBRed2, OUTPUT);
  pinMode(ledRGBGreen2, OUTPUT);
  pinMode(ledRGBBlue2, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  hpLed(numHP1, numHP2);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  ledState1 = digitalRead(led1);
  ledState2 = digitalRead(led4);

  if (buttonState1 == 1) {
    if (ledState1 == 1) {
      ledDirection = 1;
      if (currentDelay >= 300) currentDelay = currentDelay - 100;
    } else {
      numHP1--;
      hpLed(numHP1, numHP2);
      currentDelay = 1000;
    }
  }

  if (buttonState2 == 1) {
    if (ledState2 == 1) {
      ledDirection = -1;
      if (currentDelay >= 300) currentDelay = currentDelay - 100;
    } else {
      numHP2--;
      hpLed(numHP1, numHP2);
      currentDelay = 1000;
    }
  }

  led = led + ledDirection;
  if (led > 4) {
    led = 1;
    numHP2--;
    ledDirection = 1;
    currLed(5);
    hpLed(numHP1, numHP2);
    delay(1000);
  } else if (led < 1) {
    led = 4;
    numHP1--;
    ledDirection = -1;
    currLed(5);
    hpLed(numHP1, numHP2);
    delay(1000);
  }

  Serial.println(numHP1);
  if (numHP1 < 1 || numHP2 < 1) {
    numHP1 = 3;
    numHP2 = 3;
    //hpLed(numHP1, numHP2);
    for (int i = 0; i < 5; i++) {

      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      ledRGB1(0,0,1);
      ledRGB2(0,0,1);
      delay(200);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      ledRGB1(0,0,0);
      ledRGB2(0,0,0);
      delay(200);
    }
  hpLed(numHP1, numHP2);
    delay(2000);
  }
  currLed(led);
  delay(currentDelay);

}

void ledRGB1(int R, int G, int B) {

  if (R == 0) {
    digitalWrite(ledRGBRed1, LOW);
  }
  else {
    digitalWrite(ledRGBRed1, HIGH);
  }

  if (G == 0) {
    digitalWrite(ledRGBGreen1, LOW);
  }
  else {
    digitalWrite(ledRGBGreen1, HIGH);
  }

  if (B == 0) {
    digitalWrite(ledRGBBlue1, LOW);
  }
  else {
    digitalWrite(ledRGBBlue1, HIGH);
  }
}

void ledRGB2(int R, int G, int B) {

  if (R == 0) {
    digitalWrite(ledRGBRed2, LOW);
  }
  else {
    digitalWrite(ledRGBRed2, HIGH);
  }

  if (G == 0) {
    digitalWrite(ledRGBGreen2, LOW);
  }
  else {
    digitalWrite(ledRGBGreen2, HIGH);
  }

  if (B == 0) {
    digitalWrite(ledRGBBlue2, LOW);
  }
  else {
    digitalWrite(ledRGBBlue2, HIGH);
  }
}


void currLed(int cC) {
  switch (cC) {
    case 1: digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      break;
    case 2: digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      break;
    case 3: digitalWrite(led3, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led4, LOW);
      break;
    case 4: digitalWrite(led4, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led1, LOW);
      break;
    case 5: digitalWrite(led4, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led1, LOW);
      break;
    default: break;
  }
}

void hpLed(int a, int b) {
  if (a == 3) {
    ledRGB1(0, 1, 0);
  } else if (a == 2) {
    ledRGB1(1, 1, 0);
  } else if (a == 1) {
    ledRGB1(1, 0, 0);
  } else if (a < 1) {
    ledRGB1(0, 0, 0);
  }

  if (b == 3) {
    ledRGB2(0, 1, 0);
  } else if (b == 2) {
    ledRGB2(1, 1, 0);
  } else if (b == 1) {
    ledRGB2(1, 0, 0);
  } else if (b < 1) {
    ledRGB2(0, 0, 0);
  }
}
