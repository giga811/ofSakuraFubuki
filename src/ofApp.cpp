#include "ofApp.h"
#include <stdlib.h>

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetCircleResolution(32);
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofBackground(0,0,0);
    nBandsToGet = 1024;

    //画面の基本設定
//    ofBackground(0,0,0);
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    //画像データの読込み
    myImage.loadImage("sakura1.gif");
    myImage2.loadImage("sakura_moji.png");
    //myImage3.loadImage("sakura_bg.jpg"); //背景画像

    // sakura init
    for(int i=0;i<imMaxCh;i++)//　画像の変数の初期設定
    {
        imX[i]=rand()%imWx;
        imY[i]=rand()%imWy;
        imZ[i]=rand()%(imMz-1)*2-(imMz-1);
        if(rand()<0.5){imW[i]=1;}else{imW[i]=-1;}
        imH[i]=rand()%3+1;
    }
}
bool flag = false;
//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    fft = ofSoundGetSpectrum(nBandsToGet);
}


//--------------------------------------------------------------
void ofApp::draw(){
    //色の設定
    ofSetColor(255, 255, 255);

    //画像の幅と高さを所得
    int w = myImage.width;
    int h = myImage.height;

    // sakura main loop
    // myImage3.draw(0, 0, imWx, imWy); //背景画像
    myImage2.draw(20, 20, 180, 60);
    int x,y;

    for(int i=0;i<imMaxCh;i++)
    {
        imX[i]+=imZ[i];
        imA++;
        if(imA==6)
        {
            imA=0;
            imZ[i]+=imW[i];
            if(imZ[i]>imMz+2){imW[i]=-imW[i];}
            if(imZ[i]<-imMz){imW[i]=-imW[i];}
        }
        imY[i]+=imH[i];
        if(imY[i]>imWy)//　画面から消えたら上に戻す
        {
            imX[i]=rand()%imWx;
            imY[i]=-h;
            imH[i]=rand()%4+1;
            if(rand()%10>8){imH[i]=12;}//　たまに早く落ちる花びらを作る
        }
        x=imX[i];
        y=imY[i];
        
        myImage.draw(x,y); // 桜 描画
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}