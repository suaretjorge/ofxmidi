
#include "ofxMidi.h"

// the midi backend
#ifdef TARGET_OF_IPHONE
	#include "ios/ofxPGMidiIn.h"
#else
	#include "desktop/ofxPortMidiContext.h"
#endif

// -----------------------------------------------------------------------------
// TODO: replace cout with ofLogNotice when OF_LOG_NOTICE is the default log level
void ofxMidiConnectionListener::midiInputAdded(string name, bool isNetwork) {
	cout << "ofxMidi: input added: " << name << " network: " << isNetwork << endl;
}

void ofxMidiConnectionListener::midiInputRemoved(string name, bool isNetwork) {
	cout << "ofxMidi: input removed: " << name << " network: " << isNetwork << endl;
}

void ofxMidiConnectionListener::midiOutputAdded(string name, bool isNetwork) {
	cout << "ofxMidi: output added: " << name << " network: " << isNetwork << endl;
}

void ofxMidiConnectionListener::midiOutputRemoved(string name, bool isNetwork) {
	cout << "ofxMidi: output removed: " << name << " network: " << isNetwork << endl;
}

// -----------------------------------------------------------------------------
unsigned int ofxMidi::getTime() {
	//#ifdef TARGET_OS_IPHONE
	//	return 0;
	//#else
		return ofxPortMidiContext::getTime();
	//#endif
}

// -----------------------------------------------------------------------------
void ofxMidi::setConnectionListener(ofxMidiConnectionListener * listener) {
	#ifdef TARGET_OF_IPHONE
		ofxPGMidiIn::setConnectionListener(listener);
	#endif
}

// -----------------------------------------------------------------------------
void ofxMidi::clearConnectionListener() {
	#ifdef TARGET_OF_IPHONE
		ofxPGMidiIn::clearConnectionListener();
	#endif
}

// -----------------------------------------------------------------------------
void ofxMidi::enableNetworking() {
	#ifdef TARGET_OF_IPHONE
		ofxPGMidiIn::enableNetworking();
	#endif
}
