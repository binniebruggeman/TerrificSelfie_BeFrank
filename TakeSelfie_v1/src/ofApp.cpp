#include "ofApp.h"


#define GREEN_SCREEN_HUE 87
#define GREEN_SCREEN_HUE_MARGIN 10

void ofApp::setup() {
    grabber.listDevices();
    
    grabber.setDeviceID(0);
    grabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);
    grabber.setDesiredFrameRate(30);
    
    
    workspace.allocate(CAM_WIDTH, CAM_HEIGHT, OF_IMAGE_COLOR);
}

void ofApp::update() {
    grabber.update();
    
    if (grabber.isFrameNew()) {
        ofPixels& pixels = grabber.getPixels();
        for (size_t y = 0; y < pixels.getHeight(); y++) {
            for (size_t x = 0; x < pixels.getWidth(); x++) {
                
                ofColor col = pixels.getColor(x, y);
                
                workspace.setColor(x, y, col);
        
            }
        }
        
        image.setFromPixels(workspace);
           image.mirror(false, true);

    }
}

void ofApp::draw() {
    // draw the manipulated image, scaled up 3 times
    if(takeSelfie==false && beforeSelfie==true ){
    image.draw(0, 0, CAM_WIDTH * 3, CAM_HEIGHT * 3);
    }
    
    if(takeSelfie==true && beforeSelfie==true ){
        resultImage.draw(0,0);
    }
}

void ofApp::keyPressed(int key) {
    if (key == ' ') {
        
        takeSelfie = true;
        
        
        takenSelfie.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        takenSelfie.save("/Users/binniebruggeman/Desktop/HKU1718/of_v0.9.8_osx_release/apps/TerrificSelfie_BeFrank/TakeSelfie_v1/bin/data/selfie.jpg");
        
       selfieImage.load(ofToDataPath("/Users/binniebruggeman/Desktop/HKU1718/of_v0.9.8_osx_release/apps/TerrificSelfie_BeFrank/TakeSelfie_v1/bin/data/selfie.jpg"));
    originalImage.load(ofToDataPath("/Users/binniebruggeman/Desktop/HKU1718/of_v0.9.8_osx_release/apps/TerrificSelfie_BeFrank/TakeSelfie_v1/bin/data/target.jpg"));
        resultImage.allocate(originalImage.getWidth(), originalImage.getHeight(), OF_IMAGE_COLOR);
    }
}

void ofApp::mergeImages() {
    for (int x = 0; x < selfieImage.getWidth(); x++) {
        for (int y = 0; y < selfieImage.getHeight(); y++) {
            ofColor color = selfieImage.getColor(x, y);
            if (ofInRange(color.getHue(), GREEN_SCREEN_HUE-GREEN_SCREEN_HUE_MARGIN, GREEN_SCREEN_HUE+GREEN_SCREEN_HUE_MARGIN)) {
                resultImage.setColor(x, y, originalImage.getColor(x, y));
            } else {
                resultImage.setColor(x, y, selfieImage.getColor(x, y));
            }
        }
    }
    resultImage.update();
}
