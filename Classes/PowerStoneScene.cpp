//
//  powerStoneScene.cpp
//  testCocos
//
//  Created by OkuboTomohiro on 2015/07/18.
//
//

#include "PowerStoneScene.h"

USING_NS_CC;

Scene* PowerStoneScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = PowerStoneScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool PowerStoneScene::init(){
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /**ロード部*/
    userDefault = UserDefault::getInstance();
    
    //背景
    auto backStage = Sprite::create("onkeru/divination.png");
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    
    //表示する文字列
    auto drawLabel = Label::createWithSystemFont("","fonts/NotoSansCJKjp-Regular.otf",30);
    drawLabel->setColor(Color3B(255,255,255));
    std::string drawStoneLabel("パワーストーン:");
    drawStoneLabel.append(StringUtils::toString(PlayerData::sharePlayerData()->getStoneCount).c_str());
    drawStoneLabel.append("個(10個以上必要)");
    
    drawLabel->setString(drawStoneLabel);
    drawLabel->setPosition(visibleSize.width/2,visibleSize.height/2-visibleSize.height/5);
    
    //画面を白く塗りつぶす
    auto whiteOut = Sprite::create();
    whiteOut->setTextureRect(Rect(0,0,visibleSize.width,visibleSize.height));
    whiteOut->setColor(Color3B::WHITE);
    whiteOut->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    
    //押すボタン
    auto changeButton = MenuItemImage::create("onkeru/change_button.png","onkeru/change_button_push.png",CC_CALLBACK_1(PowerStoneScene::changeButtonAction,this));
    changeButton->setPosition(Vec2(320,200));
    changeButton->setScale(0.5);
    //押すボタン用のメニュー
    auto changeMenu = Menu::create(changeButton,nullptr);
    changeMenu->setPosition(Vec2(0,0));
    
    //下のメニュー
    auto downMenuBar = DownMenu::create();
    this->addChild(backStage);
    this->addChild(drawLabel);
    this->addChild(downMenuBar->getDownMenu());
    this->addChild(changeMenu);
    //this->addChild(whiteOut,-1);
    return true;
}

//押された時の処理
void PowerStoneScene::changeButtonAction(Ref* pSender){
    if(PlayerData::sharePlayerData()->getStoneCount >= 10){
        PlayerData::sharePlayerData()->minusStoneCount(10);
        srand((unsigned int)time(NULL));
        int randNum = rand()%5;
        log("Number:%d",randNum);
        switch (randNum) {
            //normal
            case 0:
                PlayerData::sharePlayerData()->playerChara = "onkeru/player_normal.png";
                PlayerData::sharePlayerData()->getOnkeru1 = true;
                userDefault->setBoolForKey("onkeru1",true);
                break;
            //mobu
            case 1:
                PlayerData::sharePlayerData()->playerChara = "onkeru/player_mobu.png";
                PlayerData::sharePlayerData()->getOnkeru2 = true;
                userDefault->setBoolForKey("onkeru2",true);
                break;
            //potya
            case 2:
                PlayerData::sharePlayerData()->playerChara = "onkeru/player_potya.png";
                PlayerData::sharePlayerData()->getOnkeru3 = true;
                userDefault->setBoolForKey("onkeru3",true);
                break;
            //smile
            case 3:
                PlayerData::sharePlayerData()->playerChara = "onkeru/player_smile.png";
                PlayerData::sharePlayerData()->getOnkeru4 = true;
                userDefault->setBoolForKey("onkeru4",true);
                break;
            //zuru
            case 4:
                PlayerData::sharePlayerData()->playerChara = "onkeru/player_zuru.png";
                PlayerData::sharePlayerData()->getOnkeru5 = true;
                userDefault->setBoolForKey("onkeru5",true);
                break;
            default:
                PlayerData::sharePlayerData()->playerChara = "onkeru/player_normal.png";
                break;
        }
        
        
        userDefault->setStringForKey("playerChara",PlayerData::sharePlayerData()->playerChara);
        
        //取得している石の取得の保存
        userDefault->setIntegerForKey("getStoneCount",PlayerData::sharePlayerData()->getStoneCount);
        userDefault->flush();
        //移動
        Director::getInstance()->replaceScene(TransitionFade::create(1.0f,MainGameScene::createScene(),Color3B::WHITE));
        
    }
}
