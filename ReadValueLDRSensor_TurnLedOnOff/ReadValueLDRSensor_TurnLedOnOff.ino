
int sensorPin = A0;   // select the input pin for ldr
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(2, OUTPUT); //pin connected to the LED
  Serial.begin(9600); //sets serial port for communication
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen
  
  if(sensorValue > 100) //setting a threshold value
  digitalWrite(2,HIGH); //turn LED ON
  
  else digitalWrite(2,LOW); //turn LED OFF
  
  delay(100);                  
}
