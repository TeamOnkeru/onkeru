//
//  TitleScene.h
//  testCocos
//
//  Created by 大久保友博 on 2015/08/28.
//
//

#ifndef __testCocos__TitleScene__
#define __testCocos__TitleScene__

#include "cocos2d.h"
#include "MainGameScene.h"
#include "PlayerData.h"
#include "talkScene.h"
class TitleScene : public cocos2d::Layer
{
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    CREATE_FUNC(TitleScene);
private:
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    int dataSaveTime;
};

#endif /* defined(__testCocos__TitleScene__) */
