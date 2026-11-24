#define lightPin 7  // LED is connected to D7
#define buttonPin 8 // Switch is connected to D8

int buttonValue;   // values of switch stores here
int buttonOld = 1;   // track 1s coming from switch 
int ledState = 1;   // track the LED waether ON oand OFF



void setup() {
Serial.begin(9600);
pinMode(buttonPin, INPUT_PULLUP);
pinMode(lightPin, OUTPUT);



}

void loop() {
buttonValue=digitalRead(buttonPin);
delay(200);

if(buttonValue==0 && buttonOld==1){

  if(ledState==1){
    digitalWrite(lightPin, HIGH);
    ledState=0;
  }else{
    digitalWrite(lightPin, LOW);
    ledState=1;
  }


}

buttonOld=buttonValue;


//digitalWrite(lightPin, HIGH);
Serial.println(buttonValue);



}
