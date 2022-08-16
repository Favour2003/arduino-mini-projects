#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define JOYSTICK_BUTTON 2
#define ledRGBRed 3
#define ledRGBGreen 4
#define ledRGBBlue 5

void setup() {
  Serial.begin(9600);
  pinMode(JOYSTICK_BUTTON, INPUT_PULLUP);
  pinMode(ledRGBRed, OUTPUT);
  pinMode(ledRGBGreen, OUTPUT);
  pinMode(ledRGBBlue, OUTPUT);
}

void loop() {
  int x = analogRead(JOYSTICK_X);
  int y = analogRead(JOYSTICK_Y);
  int button = !digitalRead(JOYSTICK_BUTTON);



  Serial.print("X: " + String(x));
  Serial.print(",\tY:" + String(y));
  Serial.println(",\tP: " + String(button));

  if ((x >= 510 && x <= 1023) && (y >= 0 && y <= 20)) {
    ledRGB(0, 0, 0);
  }
  if ((x >= 1023 && x <= 1040) && (y >= 0 && y <= 510)) {
    ledRGB(0, 0, 1);
  }
  if ((x >= 1023 && x <= 1040) && (y >= 510 && y <= 1023)) {
    ledRGB(0, 1, 0);
  }
  if ((x >= 510 && x <= 1023) && (y >= 1023 && y <= 1040)) {
    ledRGB(0, 1, 1);
  }
  if ((x >= 0 && x <= 510) && (y >= 1023 && y <= 1040)) {
    ledRGB(1, 0, 0);
  }
  if ((x >= 0 && x <= 20) && (y >= 510 && y <= 1023)) {
    ledRGB(1, 0, 1);
  }
  if ((x >= 0 && x <= 20) && (y >= 0 && y <= 510)) {
    ledRGB(1, 1, 0);
  }
  if ((x >= 0 && x <= 510) && (y >= 0 && y <= 20)) {
    ledRGB(1, 1, 1);
  }

  if (button == 1) {

    for (int i = 0; i < 10; i++) {
      for (int A = 0; A < 2; A++) {
        for (int B = 0; B < 2; B++) {
          for (int C = 0; C < 2; C++) {
            if (A == 0 && B == 0 && C == 0) {
              break;
            }
            ledRGB(A, B, C);
            delay(50);
          }
        }
      }
    }
  }
  
  delay(100);


}


void ledRGB(int R, int G, int B) {

  if (R == 0) {
    digitalWrite(ledRGBRed, LOW);
  }
  else {
    digitalWrite(ledRGBRed, HIGH);
  }

  if (G == 0) {
    digitalWrite(ledRGBGreen, LOW);
  }
  else {
    digitalWrite(ledRGBGreen, HIGH);
  }

  if (B == 0) {
    digitalWrite(ledRGBBlue, LOW);
  }
  else {
    digitalWrite(ledRGBBlue, HIGH);
  }

}
