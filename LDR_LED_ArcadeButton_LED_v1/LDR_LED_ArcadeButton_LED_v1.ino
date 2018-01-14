
//SPOTLIGHT
int ldrPin = A0;   //select the input pin for ldr
int ldrVal = 0;  //variable to store the value coming from the sensor
int spotlightPin = 2;
bool personInPlace = false;

//TAKE SELFIE
int buttonPin = 3; //select the input pin for the arcade button
int LEDPin = 4; //select the input pin for the
int buttonState = 0; //set the buttonState to 0/LOW
bool selfieTaken = false;

void setup() {
  Serial.begin(9600); //sets serial port for communication
  pinMode(spotlightPin, OUTPUT); //pin connected to the LED

  pinMode (buttonPin, INPUT_PULLUP);
  pinMode (LEDPin, OUTPUT);


}

void loop() {
  // read the value from the ldr sensor:
  ldrVal = analogRead(ldrPin);
  //Serial.println(ldrVal); //prints the values coming from the ldr sensor on the screen

  // read the state of the button, pressed or not
  buttonState = digitalRead(buttonPin);
  //Serial.println(buttonState);

  //Checking if a person is in place
  if (ldrVal > 100) {//setting a threshold value
    digitalWrite(spotlightPin, HIGH); //turn LED ON
    personInPlace = true;
    Serial.println("Person is in place.");
  } else {
    digitalWrite(spotlightPin, LOW); //turn LED OFF
    personInPlace = false;
    Serial.println("Nobody here.");
  }

  //If a person is in place, the button is pressed and there 
  //hasn't been another selfie taken yet since the person 
  //stepped in place
  if (personInPlace == true && buttonState == LOW && selfieTaken == false) {
    digitalWrite(LEDPin, HIGH); //turn LED on
    selfieTaken = true;
  } else {
    digitalWrite (LEDPin, LOW); //turn LED off
    if (selfieTaken == false) {
      Serial.println("No selfie taken yet.");
    }
  }

  if (selfieTaken == true) {
    Serial.println("Selfie taken.");
  }

  if (selfieTaken == true && personInPlace == false) {
    selfieTaken = false;
    Serial.println("RESET! Ready for new selfie.");
  }

  delay(1000);
}


