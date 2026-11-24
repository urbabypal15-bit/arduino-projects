int addswitchPin=7;
int subswitchPin=8;
int ledPin=9;
int addswitchValue;
int subswitchValue;
int counter=0;
//int count=0;
void setup() {
 Serial.begin(9600);
 pinMode(addswitchPin, INPUT_PULLUP);
 pinMode(subswitchPin, INPUT_PULLUP);
 pinMode(ledPin, OUTPUT);
}

void loop() {
addswitchValue=digitalRead(addswitchPin);
subswitchValue=digitalRead(subswitchPin);
delay(200);

if(addswitchValue==0){
  counter=counter+10;
  Serial.print("Increase the brightness: ");
 if(counter>=255){
counter=255; 

}
}

  if(subswitchValue==0){
  counter=counter-10;
  Serial.print("decrease the brightness: ");
 if(counter<=0){
  counter=0;
}
Serial.println(counter);
analogrite(ledPin, counter);
  }



}
