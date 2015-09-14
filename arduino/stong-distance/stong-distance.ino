/*
  Distance & Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

 
const int TrigPin = 2; 
const int EchoPin = 3; 
float cm; 
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 7;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
                  
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(TrigPin, OUTPUT); 
  pinMode(EchoPin, INPUT); 

}

void blink() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second  
}

void readDistance() {
  digitalWrite(TrigPin, LOW); //Low-high-low-fat one short pulse to TrigPin 
  delayMicroseconds(2); 
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TrigPin, LOW); 

  cm = pulseIn(EchoPin, !(LOW)) / 58.0; //Echo time will be converted into cm
  cm = (int(cm * 100.0)) / 100.0; //Two decimal places
  Serial.print(cm); 
  Serial.print("cm"); 
  Serial.println(); 
  delay(1000); 
  
}

// the loop routine runs over and over again forever:
void loop() {
  readDistance();
  if (cm < 10) {
    blink();
  } else {
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second  
    
  }
}
