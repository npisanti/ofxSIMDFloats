#include "ofApp.h"


// This is a simple performance test of ofxSIMDFloats
// if possible make better tests on cpu load while running your app
// run this tests with -O2 or -O3 optimization activated


//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(24);
    ofBackground(0);
    
    size = 8192;

    ofx_activate_denormal_flush();
    
    ofx_allocate_aligned( arrayX, size );
    ofx_allocate_aligned( arrayY, size );
    ofx_allocate_aligned( arrayZ, size );
    
    // getting some random values
    for(int i=0; i<size; ++i){
        arrayX[i] = ofRandom( -1.0f, 1.0f );
        arrayY[i] = ofRandom( -1.0f, 1.0f );
        arrayZ[i] = ofRandom( -1.0f, 1.0f );
    }
    
    calculateNonAccelerated();
    calculateSIMD();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    

}

void ofApp::calculateSIMD(){

#ifdef OFX_SIMD_USE_SIMD
    start = chrono::high_resolution_clock::now();    
    end = chrono::high_resolution_clock::now();    
    nanosecs = end-start; 
        
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_BaddC( arrayY, arrayX, arrayZ, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeBaddC = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_BaddS( arrayY, arrayX, 0.707f, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeBaddS = nanosecs.count();       

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_BmulC( arrayY, arrayX, arrayZ, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeBmulC = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_BmulS( arrayY, arrayX, 0.707f, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeBmulS = nanosecs.count();   

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_BsubC( arrayY, arrayX, arrayZ, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeBsubC = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_BsubS( arrayY, arrayX, 0.707f, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeBsubS = nanosecs.count();  

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_BdivC( arrayY, arrayX, arrayZ, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeBdivC = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_SsubB( arrayY, 0.707f, arrayZ, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeSsubB = nanosecs.count();  

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_Badd_CmulS( arrayY, arrayX, arrayZ, 0.707f, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeBadd_CmulS = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_1divB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    time1divB = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_absB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeabsB = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_negB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timenegB = nanosecs.count();      

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_sqrtB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timesqrtB = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_sinB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timesinB = nanosecs.count(); 
         
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_cosB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timecosB = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_tanB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timetanB = nanosecs.count();   

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_logB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timelogB = nanosecs.count();   

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_logSB( arrayY, 1.3f, arrayX, size);
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timelogSB = nanosecs.count();   

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_expB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeexpB = nanosecs.count(); 
     
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_powSB( arrayY, 1.3f, arrayX, size);
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timepowSB = nanosecs.count();  
     
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_floorB( arrayY, arrayX, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timefloorB = nanosecs.count();   

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_maxBC( arrayY, arrayX, arrayZ, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timemaxBC = nanosecs.count();   
    
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_maxBS( arrayY, arrayX, 0.707f, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timemaxBS = nanosecs.count();    
    
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_minBC( arrayY, arrayX, arrayZ, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeminBC = nanosecs.count(); 
    
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_minBS( arrayY, arrayX, 0.707f, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeminBS = nanosecs.count();       
 
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_clipB( arrayY, arrayX, -1.3f, 1.3f, size );
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeclipB = nanosecs.count();

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_line( arrayY, 0.0f, 1.0f, size);
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeline = nanosecs.count();   
    
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_ramp( arrayY, 0.0f, 0.0005f, size);
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeramp = nanosecs.count();   
    
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_Zero( arrayY, size);
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeZero = nanosecs.count();   

    start = chrono::high_resolution_clock::now();
    ofx_Aeq_B( arrayY, arrayX, size);
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeB = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_S( arrayY, 0.707f, size);
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;   
    timeS = nanosecs.count();  
#endif 

}

void ofApp::calculateNonAccelerated(){
    
    start = chrono::high_resolution_clock::now();
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = arrayX[i] + arrayZ[i];
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeBaddCnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = arrayX[i] + 0.707f;
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeBaddSnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = arrayX[i] *  arrayZ[i];
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeBmulCnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = arrayX[i] * 0.707f;
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeBmulSnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = arrayX[i] -  arrayZ[i];
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeBsubCnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = arrayX[i] - 0.707f;
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeBsubSnon = nanosecs.count();
    
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = arrayX[i] /  arrayZ[i];
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeBdivCnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = 0.707f - arrayX[i];
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeSsubBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = arrayX[i] + arrayZ[i]*0.707f;
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeBadd_CmulSnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = 1.0f / arrayX[i];
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    time1divBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = abs( arrayX[i] );
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeabsBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = - arrayX[i];
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timenegBnon = nanosecs.count();
    
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = sqrt( arrayX[i] );
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timesqrtBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = sinf( arrayX[i] );
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timesinBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = cosf( arrayX[i] );
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timecosBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = tanf( arrayX[i] );
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timetanBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = logf( arrayX[i] );
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timelogBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    float logBaseMult_f = 1.0f/ logf(1.3f);
    for( int i=0; i<size; ++i){
        arrayY[i] = logf( arrayX[i] ) * logBaseMult_f;
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timelogSBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = expf( arrayX[i] );
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeexpBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = powf(1.3f, arrayX[i] );
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timepowSBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = floorf( arrayX[i] );
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timefloorBnon = nanosecs.count();
    
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        if( arrayX[i] > arrayZ[i]){
            arrayY[i] = arrayX[i];
        }else{
            arrayY[i] = arrayZ[i];
        }
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timemaxBCnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        if( arrayX[i] > 0.707f){
            arrayY[i] = arrayX[i];
        }else{
            arrayY[i] = 0.707f;
        }
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timemaxBSnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        if( arrayX[i] < arrayZ[i]){
            arrayY[i] = arrayX[i];
        }else{
            arrayY[i] = arrayZ[i];
        }
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeminBCnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        if( arrayX[i] < 0.707f){
            arrayY[i] = arrayX[i];
        }else{
            arrayY[i] = 0.707f;
        }
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeminBSnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_clipB( arrayY, arrayX, -1.3f, 1.3f, size );
    for( int i=0; i<size; ++i){
        if( arrayX[i] < -1.3f){
            arrayY[i] = -1.3f;
        }else if( arrayX[i] > 1.3f){
            arrayY[i] = 1.3f;
        }else{
            arrayY[i] = arrayX[i];
        }
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeclipBnon = nanosecs.count();
    
    
    start = chrono::high_resolution_clock::now();
    float inc = (1.0f - 0.0f) / static_cast<float>(size);
    float now = 0.0f;
    for( int i=0; i<size; ++i){
        arrayY[i] = now;
        now+=inc;
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timelinenon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    now = 0.0f;
    for( int i=0; i<size; ++i){
        arrayY[i] = now;
        now += 0.0005f;
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timerampnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_Zero( arrayY, size);
    for( int i=0; i<size; ++i){
        arrayY[i] = 0.0f;
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeZeronon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    ofx_Aeq_B( arrayY, arrayX, size);
    for( int i=0; i<size; ++i){
        arrayY[i] = arrayX[i];
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeBnon = nanosecs.count();
    
    start = chrono::high_resolution_clock::now();
    for( int i=0; i<size; ++i){
        arrayY[i] = 0.707f;
    }
    end = chrono::high_resolution_clock::now();
    nanosecs = end-start;
    timeSnon = nanosecs.count();  
    
}



//--------------------------------------------------------------
void ofApp::draw(){
    
#ifdef OFX_SIMD_USE_SSE2
    ofDrawBitmapString("SSE2 Intrinsics Found\n", 10, 20); 
#endif

#ifdef OFX_SIMD_USE_NEON
    ofDrawBitmapString("NEON Intrinsics Found\n", 10, 20); 
#endif
    
#ifdef OFX_SIMD_USE_SIMD
    string message = "Arrays size =  ";
    message += ofToString(size);
    message += "\n";
    ofDrawBitmapString(message, 330, 20); 
    
    
    message = "function ----> SIMD / non accelerated time\n";
    ofDrawBitmapString(message, 10, 60); 
     
    int msgY = 60;   
    
    message = "A = 0.0 -----> ";
    message += ofToString(timeZero);
    message += " / ";
    message += ofToString(timeZeronon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = B  ------> ";
    message += ofToString(timeB);
    message += " / ";
    message += ofToString(timeBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = s  ------> ";
    message += ofToString(timeS);
    message += " / ";
    message += ofToString(timeSnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = B + C ---> ";
    message += ofToString(timeBaddC);
    message += " / ";
    message += ofToString(timeBaddCnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = B + s ---> ";
    message += ofToString(timeBaddS);
    message += " / ";
    message += ofToString(timeBaddSnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = B * C ---> ";
    message += ofToString(timeBmulC);
    message += " / ";
    message += ofToString(timeBmulCnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = B * s ---> ";
    message += ofToString(timeBmulS);
    message += " / ";
    message += ofToString(timeBmulSnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY);    

    message = "A = B - C ---> ";
    message += ofToString(timeBsubC);
    message += " / ";
    message += ofToString(timeBsubCnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = B - s ---> ";
    message += ofToString(timeBsubS);
    message += " / ";
    message += ofToString(timeBsubSnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY);  

    message = "A = B / C ---> ";
    message += ofToString(timeBdivC);
    message += " / ";
    message += ofToString(timeBdivCnon);
    message += " usec\n "; 
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = s - B ---> ";
    message += ofToString(timeSsubB);
    message += " / ";
    message += ofToString(timeSsubBnon);
    message += " usec\n "; 
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY);  

    message = "A = B + C*s -> ";
    message += ofToString(timeBadd_CmulS);
    message += " / ";
    message += ofToString(timeBadd_CmulSnon );
    message += " usec\n "; 
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = 1 / B ---> ";
    message += ofToString(time1divB);
    message += " / ";
    message += ofToString(time1divBnon);
    message += " usec\n "; 
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY);  

    message = "A = abs(B) --> ";
    message += ofToString(timeabsB);
    message += " / ";
    message += ofToString(timeabsBnon);
    message += " usec\n "; 
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = - B -----> ";
    message += ofToString(timenegB);
    message += " / ";
    message += ofToString(timenegBnon);
    message += " usec\n "; 
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY);  

    message = "A = sqrt(B) -> ";
    message += ofToString(timesqrtB);
    message += " / ";
    message += ofToString(timesqrtBnon);
    message += " usec\n "; 
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = sin(B) --> ";
    message += ofToString(timesinB);
    message += " / ";
    message += ofToString(timesinBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY);  
    
    message = "A = cos(B) --> ";
    message += ofToString(timecosB);
    message += " / ";
    message += ofToString(timecosBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY); 
    
    message = "A = tan(B) --> ";
    message += ofToString(timetanB);
    message += " / ";
    message += ofToString(timetanBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 10, msgY);      


    msgY = 60;


    message = "A = log(B) --> ";
    message += ofToString(timelogB);
    message += " / ";
    message += ofToString(timelogBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY);   
    
    message = "A = log_s(B)-> ";
    message += ofToString(timelogSB);
    message += " / ";
    message += ofToString(timelogSBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY);   
    
    message = "A = exp(B) --> ";
    message += ofToString(timeexpB);
    message += " / ";
    message += ofToString(timeexpBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
    
    message = "A = pow(s,B)-> ";
    message += ofToString(timepowSB);
    message += " / ";
    message += ofToString(timepowSBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
    
    message = "A = floor(B)-> ";
    message += ofToString(timefloorB);
    message += " / ";
    message += ofToString(timefloorBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
    
    
    message = "A = max(B,C)-> ";
    message += ofToString(timemaxBC);
    message += " / ";
    message += ofToString(timemaxBCnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
    
    message = "A = max(B,s)-> ";
    message += ofToString(timemaxBS);
    message += " / ";
    message += ofToString(timemaxBSnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
    
    message = "A = min(B,C)-> ";
    message += ofToString(timeminBC);
    message += " / ";
    message += ofToString(timeminBCnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
    
    message = "A = min(B,s)-> ";
    message += ofToString(timeminBS);
    message += " / ";
    message += ofToString(timeminBSnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
        
    message = "A = clip(..)-> ";
    message += ofToString(timeclipB);
    message += " / ";
    message += ofToString(timeclipBnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
    
    message = "A = line(..)-> ";
    message += ofToString(timeline);
    message += " / ";
    message += ofToString(timelinenon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
    
    message = "A = ramp(..)-> ";
    message += ofToString(timeramp);
    message += " / ";
    message += ofToString(timerampnon);
    message += " usec\n ";
    msgY+=20;
    ofDrawBitmapString(message, 330, msgY); 
    

    
#else
    ofDrawBitmapString("SIMD INTRINSICS NOT FOUND\n", 10, 20); 
#endif

  
}

//--------------------------------------------------------------
void ofApp::exit(){

    // always remember to deallocate all the allocated resources!!!
    ofx_deallocate_aligned( arrayX );
    ofx_deallocate_aligned( arrayY );
    ofx_deallocate_aligned( arrayZ );
    
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
