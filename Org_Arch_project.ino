#include <dht.h>


#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;

#define DHT11_PIN 7
const int sensorPin = A0;
const int sensorPin2 = A1;

const int D1 = 6; //Pin for touch sensor
int sensorvalue = 0;
int photoState;
int tempState;
byte counter = 0;
String songs[5];

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(sensorPin2,INPUT);

  pinMode(D1, INPUT);
  
songs[0] = "Home.mp3";
songs[1] = "All_Star.mp3";
songs[2] = "History.mp3";
songs[3] = "Little_Talks.mp3";
songs[4] = "Mountain_Sound.mp3";

}
//
void loop() {
     sensorvalue = digitalRead(D1);
      

     if (sensorvalue == 1) {
//      Serial.println("sound");
       int songNum = random(4);
       Serial.println(songs[songNum]);
     }

     //Figure out how to delay but not delay other sensors.
     if (counter == 0) {

      lcd.clear();
    int dhtVal = DHT.read11(DHT11_PIN);

    int humidity = DHT.humidity;

    tempState = analogRead(sensorPin);
    float tempVoltage = (tempState/1024.0) * 5.0;
    float temperature = (tempVoltage - .5) * 100;
    photoState = analogRead(sensorPin2);
    
    String mood = "";

    if(temperature > 23) {
      if (humidity > 50) {
        if ((photoState/10) > 50) {
          mood = "Summer Day";
          Serial.println(songs[1]);
        }
        else {
          mood = "Summer Night";
          Serial.println(songs[4]);
        }
      }
      else {
        if ((photoState/10) > 50) {
          mood = "Spring Day";
          Serial.println(songs[1]);
        }
        else {
          mood = "Spring Night";
          Serial.println(songs[4]);
        }
      }
    }
    else {
       if (humidity > 50) {
        if ((photoState/10) > 50) {
          mood = "Fall Day";
          Serial.println(songs[1]);
        }
        else {
          mood = "Fall Night";
          Serial.println(songs[4]);
        }
      }
      else {
        if ((photoState/10) > 50) {
          mood = "Winter Day";
          Serial.println(songs[1]);
        }
        else {
          mood = "Winter Night";
          Serial.println(songs[4]);
        }
      }
    }



//    Serial.println(mood);
    int newPhotoState = 0;
    
    lcd.print("L: " + String(photoState/10) + "%");
    lcd.print(" ");
    lcd.print("hum: " + String(humidity));
    lcd.setCursor(0,2);
    lcd.print("Temp: " + String(temperature));
   }
   counter++;
   delay(10);

   
    

} 
  
  
