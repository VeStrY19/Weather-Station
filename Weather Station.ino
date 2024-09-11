#include "LiquidCrystal.h"
#include "Ultrasonic.h"
#include <SimpleDHT.h>
int rs = 12;
int e = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
int dht = 7;
int ledRed = 9;
int ledBlue = 10;

SimpleDHT11 dht11(dht);
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(dht, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Temperature : ");
  lcd.setCursor(0,1);
  lcd.print("Humidite : ");
}

void loop() {
  //lcd.scrollDisplayLeft();
  //delay(500);
  // put your main code here, to run repeatedly:
  Serial.println("*******************");
  Serial.println("Simple DHT11...");

  byte temp = 0;
  byte humidite = 0;
  int err = SimpleDHTErrSuccess;
  if((err = dht11.read(&temp, &humidite, NULL) != SimpleDHTErrSuccess))
  {
    Serial.print("Read DHT11 failed, err="); 
    Serial.println(err);
    delay(1000);
    return;
  }

  Serial.print("Sample OK : ");
  Serial.print((int)temp);
  Serial.print(" *C");
  
  Serial.print((int)humidite);
  Serial.print(" H");

  lcd.setCursor(14, 0);
  lcd.print(temp);

  lcd.setCursor(10, 1);
  lcd.print(humidite);

  if (temp <= 15)
  {
    digitalWrite(ledBlue, HIGH);
    delay(250);
    digitalWrite(ledBlue, LOW);
    delay(250);
  }
  else if(temp > 15)
  {
    digitalWrite(ledRed, HIGH);
    delay(250);
    digitalWrite(ledRed, LOW);
    delay(250);
  }
  
  
  delay(1500);


  

}
