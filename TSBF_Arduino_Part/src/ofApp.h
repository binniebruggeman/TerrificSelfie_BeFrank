#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

private:
    
    //Arduino
    ofArduino arduino;
    
    //Button to take a selfie
    int buttonPin = 3;  //Arduino variables for the pins on the Arduino, connected to the sensors and actuators. (leg uit waarom ik ze hier code; later makkelijker veranderen op 1 plek ipv overal)
    int buttonState = 0;  //Arduino variables for the sensor, to check its state
    bool selfieTaken = false; //boolean to check wheter a selfie is taken (button is pressed) or not.
    
    //LDR to detect a user
    int ldrPin = A0;  //Arduino variables for the pin on the Arduino, connected to the sensor. The LDR sensor takes analogue values and therefor is connected to an analogue pin (leg uit waarom ik ze hier code; later makkelijker veranderen op 1 plek ipv overal)
    int ldrVal = 0;  //Arduino variables for the sensor, to check its value
    bool userInPlace = false; //boolean to check whether a user is in place (detected by the LDR sensor) or not.
    
    //LED to show if a user is in place or not
    int spotlightPin = 2; //using a LED for the prototype, in real life it would be an actual spotlight going on, using a relay, due to safety reasons I was not allowed to work with my 230V construction light
    
   
    
   

    
    //Arduino functions
    void setupArduino(const int& version);
    void analogPinChanged(const int& pin);
    void digitalPinChanged(const int& pin);
		
};
