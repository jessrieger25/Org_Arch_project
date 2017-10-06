#include <dht.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;

#define DHT11_PIN 7
const int sensorPin = A0;
const int sensorPin2 = A1;
int photoState;
int tempState;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(sensorPin2,INPUT);
}
//
void loop() {
    int dhtVal = DHT.read11(DHT11_PIN);
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    int humidity = DHT.humidity;
    Serial.println(DHT.humidity);  
    tempState = analogRead(sensorPin);
    float tempVoltage = (tempState/1024.0) * 5.0;
    float temperature = (tempVoltage - .5) * 100;
    photoState = analogRead(sensorPin2);
    Serial.println(photoState);
    String mood = "";

    if((photoState/10) < 50) {
      mood = "calm";
    }
    else {
      mood = "happy";
    }

    Serial.println(mood);
    int newPhotoState = 0;
    
    lcd.print("L: " + String(photoState/10) + "%");
    lcd.print(" ");
    lcd.print("hum: " + String(humidity));
    lcd.setCursor(0,2);
    lcd.print("Temp: " + String(temperature));

    delay(1000);
    lcd.clear();
    

} 
  
  
