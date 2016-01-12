#include "ofApp.h"

// Hello! this is a simple test and explanation of the ofxSIDMFloat addon for openFrameworks 

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(24);
    ofBackground(0);
    
    size = 8192;

    // treats denormalized floats as zeroes when using SIMD operation on SSE cpus
    // if you are using a NEON cpu you can also ignore this, it won't do anything as 
    // flush to zero is the standard NEON behavior.
    ofx_activate_denormal_flush();
    
    // allocate array of memory-aligned floats to the given pointers, also set all the floats to zero
    ofx_allocate_aligned( arrayX, size );
    ofx_allocate_aligned( arrayY, size );
    ofx_allocate_aligned( arrayZ, size );
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // getting some random values
    for(int i=0; i<size; ++i){
        arrayX[i] = ofRandom( -1.0f, 1.0f );
        arrayY[i] = ofRandom( -1.0f, 1.0f );
        arrayZ[i] = ofRandom( -1.0f, 1.0f );
    }
    
    // ok, the function are self explanatory, the arguments to give them are stated
    // in the function name, A, B and C are always arrays, S is always a scalar
    // the last argument (len) is always the number of the elements to calculate
    //                              and has to be no more than the allocated size
    
    // you can allocate and operate also on odd sizes as the last elements are calculated without SIMD
    // but you will get the best results with sizes that are multiples of 16 elements
    
    // also avoid using ofsetted pointers (e.g.: arrayX+7 ) as function arguments
    
    
    //------------FUNCTIONS INDEX--------------
    // for each element a = b + c
    ofx_Aeq_BaddC( arrayY, arrayX, arrayZ, size );
    
    // for each element a = b + s
    ofx_Aeq_BaddS( arrayY, arrayX, 0.707f, size );
    
    // for each element a = b * c
    ofx_Aeq_BmulC( arrayY, arrayX, arrayZ, size );
    
    // for each element a = b * s
    ofx_Aeq_BmulS( arrayY, arrayX, 0.707f, size );
    
    // for each element a = b - c
    ofx_Aeq_BsubC( arrayY, arrayX, arrayZ, size );
    
    // for each element a = b - s
    ofx_Aeq_BsubS( arrayY, arrayX, 0.707f, size );
    
    // for each element a = b / c
    ofx_Aeq_BdivC( arrayY, arrayX, arrayZ, size );
    
    // for each element a = s - b 
    ofx_Aeq_SsubB( arrayY, 0.707f, arrayZ, size );
    
    // for each element a = b + (c*s)
    ofx_Aeq_Badd_CmulS( arrayY, arrayX, arrayZ, 0.707f, size );
    
    // for each element a = 1/b
    ofx_Aeq_1divB( arrayY, arrayX, size );
    
    // for each element a is the absolute value of b
    ofx_Aeq_absB( arrayY, arrayX, size );
    
    // for each element a = -b
    ofx_Aeq_negB( arrayY, arrayX, size );
    
    // for each element a is the square root of b
    ofx_Aeq_sqrtB( arrayY, arrayX, size );
    
    // for each element a = sin(b)
    ofx_Aeq_sinB( arrayY, arrayX, size );
    
    // for each element a = cos(b)
    ofx_Aeq_cosB( arrayY, arrayX, size );
    
    // for each element a = tan(b)
    ofx_Aeq_tanB( arrayY, arrayX, size );
    
    // for each element a is the natural logarithm of b 
    ofx_Aeq_logB( arrayY, arrayX, size );
    
    // for each element a is the exponential value of b
    ofx_Aeq_expB( arrayY, arrayX, size );
    
    // for each element a is b rounded downward
    ofx_Aeq_floorB( arrayY, arrayX, size );
    
    // for each element a is the logarithm of b in s base
    ofx_Aeq_logSB( arrayY, 2.0f, arrayX, size);
    
    // for each element a is s elevated to b
    ofx_Aeq_powSB( arrayY, 2.0f, arrayX, size);
    
    // for each element b and c are comparated and the highest is set as a
    ofx_Aeq_maxBC( arrayY, arrayX, arrayZ, size );
    
    // for each element b and s are comparated and the highest is set as a
    ofx_Aeq_maxBS( arrayY, arrayX, 0.707f, size );
    
    // for each element b and c are comparated and the lowest is set as a
    ofx_Aeq_minBC( arrayY, arrayX, arrayZ, size );
    
    // for each element b and s are comparated and the lowest is set as a
    ofx_Aeq_minBS( arrayY, arrayX, 0.707f, size );
    
    // for each element a is b clamped to rangeLo and rangeHi
    ofx_Aeq_clipB( arrayY, arrayX, -1.0f, 1.0f, size );
    
    // fill the A array with numbers making a line from the start value to the end value
    // BEWARE: the end value is not included in the line
    ofx_Aeq_line( arrayY, 0.0f, 1.0f, size);
    
    // fill the A array with numbers starting from the start value and 
    // incremented by the inc value for each position
    ofx_Aeq_ramp( arrayY, 0.0f, 0.0005f, size);
    
    // set the element of A to zero
    ofx_Aeq_Zero( arrayY, size);
    
    // set the element of A to a scalar number
    // Note: this function was fastest when optimized by the compiler so it has no SIMD code inside
    ofx_Aeq_S( arrayY, 0.707f, size);
    
    // copy the element of B to A
    ofx_Aeq_B( arrayY, arrayX, size);
    
    // set the element of A in the given range to zero
    // BEWARE: the range as to be inside of the allocated space, index are not checked
    ofx_Aeq_Zero_range( arrayY, 61, 700);
    
    // set the element of A in the given range to a given scalar
    // BEWARE: the range as to be inside of the allocated space, index are not checked
    ofx_Aeq_S_range( arrayY, 0.707f, 61, 700);
    
    //---------------------------------------
    
    // you can also alias the inputs, for example to make Y = Y + (X+S)
    ofx_Aeq_Badd_CmulS( arrayY, arrayY, arrayX, 0.707f, size );
    // or for example Z = sin(Z)
    ofx_Aeq_sinB( arrayZ, arrayZ, size );


}

//--------------------------------------------------------------
void ofApp::exit(){

    // always remember to deallocate all the allocated resources!!!
    // NOTE: ofx_deallocate_aligned( float* &toDelete ) also set the pointer to nullptr
    ofx_deallocate_aligned( arrayX );
    ofx_deallocate_aligned( arrayY );
    ofx_deallocate_aligned( arrayZ );
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    #ifdef OFX_SIMD_USE_SSE2
    ofDrawBitmapString("SSE2 Intrinsics Found\n", 20, 20); 
    #endif

    #ifdef OFX_SIMD_USE_NEON
    ofDrawBitmapString("NEON Intrinsics Found\n", 20, 20); 
    #endif

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
