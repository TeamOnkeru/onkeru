//
//  TitleScene.cpp
//  testCocos
//
//  Created by 大久保友博 on 2015/08/28.
//
//

#include "TitleScene.h"
USING_NS_CC;

Scene* TitleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TitleScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool TitleScene::init(){
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto backStage = Sprite::create("onkeru/onkeru_back.jpg");
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    /*タイトル文字*/
    auto titleLogo = Sprite::create("titleLogo.png");
    titleLogo->setPosition(Vec2(backStage->getContentSize().width/2,backStage->getContentSize().height/2+200));
    /*Label*/
    auto pushLabel = Label::createWithSystemFont("-START!-","fonts/NotoSansCJKjp-Regular.otf",60);
    pushLabel->setColor(Color3B(0,0,0));
    pushLabel->setPosition(Vec2(backStage->getContentSize().width/2,backStage->getContentSize().height/2-200));
    
    /**ロード部*/
    auto userDefault = UserDefault::getInstance();
    dataSaveTime = userDefault->getIntegerForKey("saveTime",-1);
    log("testtest:%d",dataSaveTime);
    if(dataSaveTime == -1){
        PlayerData::sharePlayerData()->talkURL = "talkEvent/tutorial.txt";
    }else{
      PlayerData::sharePlayerData()->loadSetSaveTime(dataSaveTime);
      PlayerData::sharePlayerData()->getStoneCount = userDefault->getIntegerForKey("getStoneCount",0);
      PlayerData::sharePlayerData()->downStoneCount = userDefault->getIntegerForKey("downStoneCount",0);
      PlayerData::sharePlayerData()->playerChara = userDefault->getStringForKey("playerChara","onkeru/player_normal.png");
      PlayerData::sharePlayerData()->getOnkeru1 = userDefault->getBoolForKey("onkeru1",false);
      PlayerData::sharePlayerData()->getOnkeru2 = userDefault->getBoolForKey("onkeru2",false);
      PlayerData::sharePlayerData()->getOnkeru3 = userDefault->getBoolForKey("onkeru3",false);
      PlayerData::sharePlayerData()->getOnkeru4 = userDefault->getBoolForKey("onkeru4",false);
      PlayerData::sharePlayerData()->getOnkeru5 = userDefault->getBoolForKey("onkeru5",false);
      PlayerData::sharePlayerData()->talkURL = "talkEvent/tutorial.txt";
    }
    
    /*タッチ処理*/
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan,this);
    
    this->addChild(backStage);
    this->addChild(titleLogo);
    this->addChild(pushLabel);
    auto dip = Director::getInstance()->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

/**画面がタップされたときの処理*/
bool TitleScene::onTouchBegan(Touch *touch, Event *event){
    if(dataSaveTime == -1){
        Director::getInstance()->replaceScene(TransitionFade::create(1.0f,talkScene::createScene()));
    }else{
        Director::getInstance()->replaceScene(TransitionFade::create(1.0f,MainGameScene::createScene()));
    }
    return true;
}