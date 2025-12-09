#include <RF433.h> 
RF433 transmitter(7);
7 const int button1 = 2; 
const int button2 = 3; 
 
void setup() { 
pinMode(button1, INPUT_PULLUP); 
pinMode(button2, INPUT_PULLUP); 
} 
 
void loop() { 
if (digitalRead(button1) == LOW) { 
transmitter.send("HELP_NEEDED");
elay(500); 
} 
if (digitalRead(button2) == LOW) { 
transmitter.send("WATER_REQUEST"); 
delay(500); 
} 
}
#include <LiquidCrystal.h> 
RF433 receiver(7); // Bluetooth module connected to pin 7 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int buzzer = 8; 
void setup() { 
pinMode(buzzer, OUTPUT); 
lcd.begin(16,2); 
} 
 
void loop() { 
String message = receiver.receive(); 
lcd.clear(); 
if (message == "HELP_NEEDED") { 
lcd.print("Help Required!"); 
digitalWrite(buzzer, HIGH); 
delay(2000); 
digitalWrite(buzzer, LOW); 
} 
if (message == "WATER_REQUEST") { 
lcd.print("Water Needed!"); 
} 
} 