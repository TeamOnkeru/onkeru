//
//  talkScene.h
//  testCocos
//
//  Created by OkuboTomoihiro on 2015/06/28.
//
//

#ifndef __testCocos__talkScene__
#define __testCocos__talkScene__

#include "cocos2d.h"

class talkScene : public cocos2d::Layer{
private:
    void readText(std::string fileName);
    std::vector<std::string> split(const std::string& input, char delimiter);
    std::vector<std::vector<std::string>> readTextData;
    //std::vector<cocos2d::Label*> drawLabel;
    cocos2d::Label* drawLabel;  //ラベル
    cocos2d::Label* nameLabel;  //キャラクター名
    cocos2d::Sprite* backStage; //背景画像
    int drawLabelCount;  //表示した文字の行数を格納（現在表示する文字列の行数）
    bool readFlag;  //読み込みのフラグ（クリックされるのを待つ時はfalse）
    cocos2d::Sprite* rightChara; //右側キャラクター
    cocos2d::Sprite* leftChara; //右側キャラクター
    
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    void readTextToDrawObject(std::string flag);
    bool onTouchBegan(cocos2d::Touch *touch,cocos2d::Event * event);
    void update(float delta);
    CREATE_FUNC(talkScene);
};

#endif /* defined(__testCocos__talkScene__) */
