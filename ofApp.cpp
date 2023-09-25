#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}


//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofRotateX(15);

	auto radius = 230;
	ofColor color;

	for (int y = 0; y <= 1200; y += 30) {

		auto param = ofGetFrameNum() * 5 + y;
		for (int deg_start = param; deg_start < param + 360; deg_start += 90)
		{
			for (int deg = deg_start; deg < deg_start + 30; deg++) {

				auto alpha = ofMap(deg, deg_start, deg_start + 45, 0, 255);
				auto hue = ofMap(y % 100, 0, 100, 0, 255);
				color.setHsb(hue, 150, 255, alpha);

				ofSetColor(color);

				ofDrawSphere(radius * cos(deg * DEG_TO_RAD), y - 600, radius * sin(deg * DEG_TO_RAD), ofMap(deg, deg_start, deg_start + 30, 1, 7));
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}