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
#include "tapClass.h"
#include "PlayerData.h"
#include "PowerStoneScene.h"
#include "DownMenu.h"
#include "time.h"
#include <string>

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
    cocos2d::Sprite* player;    //プレイヤーのスプライト
    void update(float delta);   //update関数
    std::vector<tapClass*> stoneArray;  //落ちている石の配列
    void addStone(/*float delta*/);     //石を追加する関数
    void timeInit();  //save時間の初期化
    void stoneTimeManage(int elapsedTime);  //時間による石の管理
    const int MAX_STONE =15;    //ステージ上に表示される石の最大数
    cocos2d::UserDefault* userDefault;   //セーブの変数
};


#endif /* defined(__testCocos__MainGameScene__) */
