/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int led = 10;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  
int potPin=A0;
int potVal=0;
// how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {

  Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  potVal= analogRead(potPin);
  potVal=map(potVal,0,1023,0,255);
  // set the brightness of pin 9:
  analogWrite(led, potVal);
  Serial.println(potVal);
}
