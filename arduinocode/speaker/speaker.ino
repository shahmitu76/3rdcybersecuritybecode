int speakerPin=10;
int potpin = A0;
int sensorValue=0;
int buttonPin= 2;
bool buttonState= false;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  

}

// the loop function runs over and over again forever
void loop() {
  
  buttonState= digitalRead(buttonPin);

  if(buttonPin ==true) {
    Serial.println(buttonState);

  
  tone(speakerPin,440);
  }
  
else {
    noTone(speakerPin);
     }
}
