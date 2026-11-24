 int lightPin=A1;
 int greenLED=7;
 int yellowLED=8;
 int redLED=9;
 int buzzer=10;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel=analogRead(lightPin);
  Serial.println(lightLevel);

  if (lightLevel < 500) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  }

  else if (lightLevel <= 800) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(500);
    digitalWrite(yellowLED, LOW);
     delay(500);
  }

  else {
    // High-light alert
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
  }
}
