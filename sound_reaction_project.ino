int soundPin = 3;
int ledPin = 4;
int soundValue;
int soundOld = 0;
int ledState = 1;

void setup() {
  Serial.begin(9600);
  pinMode(soundPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  soundValue = digitalRead(soundPin);
  Serial.println(soundValue);
  
  if (soundValue == 1 && soundOld== 0) {

    if(ledState==1){
    digitalWrite(ledPin, HIGH);
    ledState=0;
  }else {
    digitalWrite(ledPin, LOW);
    ledState=1;
  }
  
}
soundOld=soundValue;
}

