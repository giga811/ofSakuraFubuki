#pragma once

#include "ofMain.h"


const int imMaxCh = 100;//　最大画像数

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofImage myImage; //画像ファイルより読みこまれたイメージデータ
    ofImage myImage2; // sakura title
    ofImage myImage3; // sakura bg
    ofImage grabbedImage; //画面をキャプチャーしたイメージデータ
    float * fft;
    int nBandsToGet;

    // sakura
    int imX[imMaxCh];//　画像の座標
    int imY[imMaxCh];
    int imZ[imMaxCh];//　Ｘ軸方向へのの加速度
    int imW[imMaxCh];//　加速度への加算減算フラグ
    int imH[imMaxCh];//　Ｙ軸方向への加速度
    int imMz=8;//　振幅の大きさ
    int imA=0;
    int imWx = 1024;// 1024,768
    int imWy = 768;//　ウインドウの幅と高さ
};
