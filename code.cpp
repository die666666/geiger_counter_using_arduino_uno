Code for Geiger counter 
A) For scanning lcd 
// Arduino 16x2 LCD I2C Scanner
/*
Analog Pin 4 - SDA
Analog pin 5 - SCL
5V  - Vcc
GND - GND
*/

#include <Wire.h>
void setup()
{
Wire.begin();
Serial.begin(9600);
Serial.println("\nI2C Scanner");
}
void loop()
{
byte error, address;
int Devices;
Serial.println("Scanning...");
Devices = 0;
for(address = 1; address < 127; address++ )
{

Wire.beginTransmission(address);
error = Wire.endTransmission();
if (error == 0)
{
Serial.print("I2C device found at address 0x");
if (address<16)
Serial.print("0");
Serial.print(address,HEX);
Serial.println("  !");
Devices++;
}
else if (error==4)
{
Serial.print("Unknown error at address 0x");
if (address<16)
Serial.print("0");
Serial.println(address,HEX);
}
}
if (Devices == 0)
Serial.println("No I2C devices found\n");
else
Serial.println("done\n");
delay(5000);          
}

B) for calculating radiation value
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystallcd(3,4,5,6,7,8);



// Conversion factor - CPM to uSV/h
#define CONV_FACTOR 0.00812

// Variables
intgeiger_input = 2;
long count = 0;
longcountPerMinute = 0;
longtimePrevious = 0;
longtimePreviousMeassure = 0;
long time = 0;
longcountPrevious = 0;
floatradiationValue = 0.0;

void setup()
{
pinMode(geiger_input, INPUT);
digitalWrite(geiger_input,HIGH);


Serial.begin(19200);

  //set up the LCD\'s number of columns and rows:
lcd.begin(16, 4);
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Radiation Sensor");
lcd.setCursor(0,1);
lcd.print("Board - Arduino");  
delay(1000);

lcd.clear();
lcd.setCursor(0, 0);
lcd.print(" hello ");
delay(1000);

lcd.clear();
lcd.setCursor(0,1);  
lcd.print("Geiger count");
delay(500);
for (inti=0;i<5;i++){
delay(200);  
lcd.scrollDisplayLeft();
  }
delay(500);

lcd.clear();
lcd.setCursor(0, 0);
lcd.print(" group no. 12 ");
lcd.setCursor(0,1);
lcd.print("mini project");    
delay(1000);

lcd.clear();  
lcd.setCursor(0, 0);
lcd.print("CPM=");
lcd.setCursor(4,0);
lcd.print(6*count);
lcd.setCursor(0,1);
lcd.print(radiationValue);

attachInterrupt(0,countPulse,FALLING);

}

void loop(){
if (millis()-timePreviousMeassure> 10000){
countPerMinute = 6*count;
radiationValue = countPerMinute * CONV_FACTOR;
timePreviousMeassure = millis();
Serial.print("cpm = "); 
Serial.print(countPerMinute,DEC);
Serial.print(" - ");
Serial.print("uSv/h = ");
Serial.println(radiationValue,4);      
lcd.clear();    
lcd.setCursor(0, 0);
lcd.print("CPM=");
lcd.setCursor(4,0);
lcd.print(countPerMinute);
lcd.setCursor(0,1);
lcd.print(radiationValue,4);
lcd.setCursor(6,1);
lcd.print("uSv/h");
  }

}

voidcountPulse(){
detachInterrupt(0);
count++;
while(digitalRead(2)==0){
  }
attachInterrupt(0,countPulse,FALLING);
}


