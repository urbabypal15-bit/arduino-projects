int redPin=8;
int greenPin=7;
int yellowPin=12;
int buzzer=4;
int potPin=A1;
int potValue;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(buzzer, OUTPUT);  
  pinMode(potPin, INPUT); 
  Serial.begin(9600); 

}

void loop() {
  potValue=analogRead(potPin);
  Serial.println(potValue);
  delay(500);

  if(potValue >0 && potValue<=450){ //for green LED
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(buzzer, LOW);

  }
 
 if(potValue>450 && potValue<901) { //for yellow LED
 digitalWrite(yellowPin, HIGH);
 digitalWrite(redPin, LOW);
 digitalWrite(greenPin, LOW);
 digitalWrite(buzzer, LOW);

 }

if(potValue>901 && potValue<1023) { //for red and buzzer
digitalWrite(redPin, HIGH);
digitalWrite(buzzer, HIGH);
digitalWrite(yellowPin, LOW);
digitalWrite(greenPin, LOW);

}

}
