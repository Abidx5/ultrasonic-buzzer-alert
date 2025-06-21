/*
 * - VCC  -> 5VDC
 * - TRIG -> Pin 9
 * - ECHO -> Pin 8
 * - GND  -> GND
 */

int trigPin = 9;    // TRIG pin
int echoPin = 8;    // ECHO pin 
int led = 7;
int randomTone;
int randomTime;
int i;



float duration_us, distance_cm;

void setup() {
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);

  

//set the initial instance to 5 seconds
randomTime = 5;
pinMode(7,OUTPUT);

  

}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = duration_us * 0.034 / 2;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  if(distance_cm < 100){
     digitalWrite(led, HIGH);
     Serial.println("Buzzer Active");



//randomTime is the number of seconds to wait

//select a random tone in audible range

delay(2000);



for (int i = 0; i < 30; i++) {
  randomTone = random(5005, 10000);
  tone(7, randomTone, 150);
  delay(150);
}

// delay(200);
// turn off tone function for pin 6

  }
  else{
    digitalWrite(led , LOW);
  }
  delay(500);




}
