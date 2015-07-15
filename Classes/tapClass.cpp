//
//  tapClass.cpp
//  testCocos
//
//  Created by OkuboTomoihiro on 2015/06/19.
//
//

#include "tapClass.h"
USING_NS_CC;

tapClass* tapClass::create(const char *img){
    tapClass* taps = new tapClass();
    if(taps && taps->init(img)){
        taps->autorelease();
        return taps;
    }
    CC_SAFE_DELETE(taps);
    return nullptr;
}
bool tapClass::init(const char *img){
    state = true;
    return this->initWithFile(img);
}

void tapClass::Collision(Sprite* player){
    //if(state == true){
        Rect rec1 = this->getBoundingBox();
        Rect rec2 = player->getBoundingBox();
        if(rec1.intersectsRect(rec2)){
            //return true;
            this->removeFromParent();
            //log("aaa");
            state = false;
        }
    //}
        
    //return false;
}

bool tapClass::getState(){
    return state;
}

