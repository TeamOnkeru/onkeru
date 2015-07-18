//
//  MainGameScene.h
//  testCocos
//
//  Created by OkuboTomoihiro on 2015/07/10.
//
//

#ifndef __testCocos__MainGameScene__
#define __testCocos__MainGameScene__

#include "cocos2d.h"
//#include "ui/CocosGUI.h"
#include "tapClass.h"
#include "PlayerData.h"
#include "PowerStoneScene.h"

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
    void update(float delta);
    void setDownMenu();
    /*ボタンの処理*/
    void homeButtonAction(Ref *pSender);
    void powerStoneButtonAction(Ref *pSender);
    void storyButtonAction(Ref *pSender);
    void collectionButtonAction(Ref *pSender);
    void posterButtonAction(Ref *pSender);
    /*落ちている石の配列*/
    std::vector<tapClass*> stoneArray;
    void addStone(float delta);
    //bool SpriteCollision(cocos2d::Sprite* col1,cocos2d::Sprite* col2);
   // void update(float delta);
};


#endif /* defined(__testCocos__MainGameScene__) */
