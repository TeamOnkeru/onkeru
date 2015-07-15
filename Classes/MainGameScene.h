//
//  MainGameScene.h
//  testCocos
//
//  Created by 大久保友博 on 2015/07/10.
//
//

#ifndef __testCocos__MainGameScene__
#define __testCocos__MainGameScene__

#include "cocos2d.h"
#include "tapClass.h"

class MainGameScene : public cocos2d::Layer
{
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    CREATE_FUNC(MainGameScene);
private:
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    cocos2d::Sprite* player;
    tapClass* stoneTest;
    void update(float delta);
    std::vector<tapClass*> stoneArray;
    //bool SpriteCollision(cocos2d::Sprite* col1,cocos2d::Sprite* col2);
   // void update(float delta);
};


#endif /* defined(__testCocos__MainGameScene__) */
