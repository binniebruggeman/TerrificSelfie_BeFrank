#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    arduino.connect("check mijn port");
    arduino.sendFirmwareVersionRequest();
}

//--------------------------------------------------------------
void ofApp::update(){

    arduino.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::setupArduino(const int& version) {
    
    //Look for arduino, and show firmware
    ofLog() << "Arduino firmware found " << arduino.getFirmwareName()
    << arduino.getMajorFirmwareVersion()
    << arduino.getMinorFirmwareVersion() << endl;
    
    //Setup pins
    arduino.sendDigitalPinMode(buttonPin, ARD_INPUT);
    arduino.sendAnalogPinReporting(ldrPin, ARD_ANALOG);
   
    
    //Setup listeners for the input on the arduinoboard
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
}
