#include "ofApp.h"

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

    mySound.loadSound("test.mp3");
    mySound.setLoop(true);
    mySound.play();
    ofSetLineWidth(3);
}
bool flag = false;
//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    fft = ofSoundGetSpectrum(nBandsToGet);
}

//-------SAKURA
void sakura() {
    int imMaxCh=20;//　最大画像数
    int imX[imMaxCh];//　画像の座標
    int imY[imMaxCh];
    int imZ[imMaxCh];//　Ｘ軸方向へのの加速度
    int imW[imMaxCh];//　加速度への加算減算フラグ
    int imH[imMaxCh];//　Ｙ軸方向への加速度
    int imMz=8;//　振幅の大きさ
    int imA=0;
    int imWx;
    int imWy;//　ウインドウの幅と高さ

    for(int i=0;i<imMaxCh;i++)
    {
        int j=rand()%2+1;
        //document.write("<img src='sakura"+j+".gif' style='position:absolute;left:-200px;' name='imch"+i+"'>");
        myImage.draw(0, -20);
    }
    imgInit();
    function imgInit()//　初期設定
    {

        imMxSet();
        for(int i=0;i<imMaxCh;i++)//　画像の変数の初期設定
        {
            imX[i]=Math.floor(Math.random()*imWx);
            imY[i]=Math.floor(Math.random()*imWy);
            imZ[i]=Math.floor(Math.random()*(imMz-1)*2)-(imMz-1);
            if(Math.random()<0.5){imW[i]=1;}else{imW[i]=-1;}
            imH[i]=Math.floor(Math.random()*4)+1;
        }
        imMain();
    }
    function imMxSet()//　ウインドウをリサイズした時にウインドウの幅と高さを取得
    {
        if(bw==1)//　ネスケの場合
        {
            imWx=window.innerWidth+window.pageXOffset-15;
            imWy=window.innerHeight+window.pageYOffset;
        }
        if(bw==2)//　IEの場合
        {
            imWx=window.document.body.clientWidth+document.body.scrollLeft;
            imWy=window.document.body.clientHeight+document.body.scrollTop;
        }
    }




    function imMain()//　メインルーチン
    {
        int x,y;
        imMxSet();
        for(int i=0;i<imMaxCh;i++)
        {
            imX[i]+=imZ[i];
            imA++;
            if(imA==3)
            {
                imA=0;
                imZ[i]+=imW[i];
                if(imZ[i]>imMz+2){imW[i]=-imW[i];}
                if(imZ[i]<-imMz){imW[i]=-imW[i];}
            }
            imY[i]+=imH[i];
            if(imY[i]>imWy)//　画面から消えたら上に戻す
            {
                imX[i]=Math.floor(Math.random()*imWx);
                imY[i]=-document.images["imch"+i].height;
                imH[i]=Math.floor(Math.random()*4)+1;
                if(Math.random()>0.8){imH[i]=16;}//　たまに早く落ちる花びらを作る
            }
            x=imX[i];
            y=imY[i];
            if(bw==1){
                if(x>imWx-document.images["imch"+i].width-16){x=-100;}
            }else{
                if(x>imWx-document.images["imch"+i].width){x=-100;}
            }
            if(y>imWy-document.images["imch"+i].height){y=-100;}
            document.images["imch"+i].style.left=x;//　画像の座標の変更
            document.images["imch"+i].style.top=y;
        }
        if(bw==2){setTimeout("imMain()",50);}else{setTimeout("imMain()",40);}//　割込処理
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    float width = float(ofGetWidth())/float(nBandsToGet)/2.0f;
    for(int i=0;i<nBandsToGet;i++){
        int b=float(255)/float(nBandsToGet)*i;
        int g=0;
        int r=255-b;
        ofColor(255,0,0);
//        ofRotateZ(i);
        ofLine(width*i*3,ofGetHeight(),width*i*3+fft[i],ofGetHeight()+fft[i]*-500);
    }
    ofTranslate(width/2,0);

    //色の設定
    ofSetColor(255, 255, 255);
    //読み込んだ画像データを画面に描画
    myImage.draw(20,20);
    myImage.draw(100, 100);
    //画像データのビットマップ情報を配列に格納
    unsigned char * pixels = myImage.getPixels();
    //画像の幅と高さを所得
    int w = myImage.width;
    int h = myImage.height;

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