#include <DHT.h>
#define  DHTPIN 3
#define DHTTYPE DHT11
DHT temp(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
 temp.begin();  

}

void loop() {
  float humidity = temp.readHumidity();
  float temperature = temp.readTemperature();

  float tempF = temp.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("% ");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.println("Temperature in Fahrenheit: ");
  Serial.print(tempF);
  Serial.println(" f");
  delay(2000);
}
