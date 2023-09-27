
int speakerPin = 10;
int potpin = A0;
int sensorValue=0;
int buttonPin= 2;
bool buttonState= false;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(speakerPin,OUTPUT);
  pinMode(5,INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println(digitalRead(5));
  buttonState= digitalRead(buttonPin);

  if(buttonPin ==true) {
  tone(speakerPin,400);
  sensorValue=analogRead(potpin);
  sensorValue= map(sensorValue,0,1023,1000,10000);
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(sensorValue);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(sensorValue);                      // wait for a second
}
else {
    digitalWrite(LED_BUILTIN,LOW);
    noTone(speakerPin);
     }
}
