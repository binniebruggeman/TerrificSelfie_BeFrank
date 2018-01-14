int buttonPin = 3; //select the input pin for the arcade button
int LEDPin = 4;
bool buttonState = 0;

void setup() {
  Serial.begin(9600); //sets serial port for communication
  pinMode (buttonPin, INPUT_PULLUP);
  pinMode (LEDPin, OUTPUT);
}

void loop() {
 buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  
  if (buttonState == LOW){ //if the button is pressed
    digitalWrite(LEDPin, HIGH); //turn LED on
    } else {
        digitalWrite (LEDPin, LOW); //turn LED off
      }
}
