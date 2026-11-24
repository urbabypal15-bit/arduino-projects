const int NUM = 3;
const int ledPins[NUM] = {8, 9, 10};
const int buttonPins[NUM] = {2, 3, 4,};
const int tones[NUM] = {262, 330, 392};
const int buzzerPin = 6;

int sequence[50];
int level = 0;

void setup() {
 for (int i = 0; i < NUM; i++) {
  pinMode(ledPins[i], OUTPUT);
  pinMode(buttonPins[i], INPUT_PULLUP);
 }  
pinMode(buzzerPin, OUTPUT);
randomSeed(analogRead(A1));
}

void flash(int i, int ms) {
  digitalWrite(ledPins[i], HIGH);
  tone(buzzerPin, tones[i]);
  delay(ms);
  digitalWrite(ledPins[i], LOW);
  noTone(buzzerPin);

}

int waitForButton() {
  while (true) {
    for (int i = 0; i < NUM; i++) {
     if (digitalRead(buttonPins[i]) == LOW) {
      flash(i, 200);
      while (digitalRead(buttonPins[i]) == LOW);
      delay(50);
      return i;
        }
      }
    }
  }


  void gameOver(){
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < NUM; j++) digitalWrite(ledPins[j], HIGH);
      tone(buzzerPin, 100);
      delay(300);
      for (int j = 0; j < NUM; j++) digitalWrite(ledPins[j], LOW);
      noTone(buzzerPin);
      delay(200);
    }
    level = 0;
    delay(1000);
  }

  void loop() {
    sequence[level] = random(NUM);
    level++;

    delay(500);
    for (int i = 0; i < level; i++) {
      if (waitForButton() != sequence[i]) {
        gameOver();
        return;
      }
    }
  }

