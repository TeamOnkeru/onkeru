//
//  MainGameScene.cpp
//  testCocos
//
//  Created by OkuboTomoihiro on 2015/07/10.
//
//

#include "MainGameScene.h"
#include "tapClass.h"
USING_NS_CC;

Scene* MainGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainGameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    // return the scene
    return scene;
}

bool MainGameScene::init(){
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    /*タッチ処理*/
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(MainGameScene::onTouchBegan,this);
    
    /**ロード部*/
    userDefault = UserDefault::getInstance();
    auto dataSaveTime = userDefault->getIntegerForKey("saveTime",-1);
    
    //userDefault->setStringForKey("playerChara","onkeru/player_normal.png");
    
    if(dataSaveTime == -1){
        /*開始時間時間の取得*/
        timeInit();
    }/*
    else{
        PlayerData::sharePlayerData()->loadSetSaveTime(dataSaveTime);
        PlayerData::sharePlayerData()->getStoneCount = userDefault->getIntegerForKey("getStoneCount",0);
        PlayerData::sharePlayerData()->downStoneCount = userDefault->getIntegerForKey("downStoneCount",0);
        PlayerData::sharePlayerData()->playerChara = userDefault->getStringForKey("playerChara","onkeru/player_normal.png");
        PlayerData::sharePlayerData()->getOnkeru1 = userDefault->getBoolForKey("onkeru1",false);
        PlayerData::sharePlayerData()->getOnkeru2 = userDefault->getBoolForKey("onkeru2",false);
        PlayerData::sharePlayerData()->getOnkeru3 = userDefault->getBoolForKey("onkeru3",false);
        PlayerData::sharePlayerData()->getOnkeru4 = userDefault->getBoolForKey("onkeru4",false);
        PlayerData::sharePlayerData()->getOnkeru5 = userDefault->getBoolForKey("onkeru5",false);
    }*/
    
    /*初期の石を配置*/
    for (int i =0; i<PlayerData::sharePlayerData()->downStoneCount; i++) {
        addStone();
    }
    
    
    
    //"onkeru/player_mock.png"
    player = Sprite::create(PlayerData::sharePlayerData()->playerChara);
    player->setScale(0.8);
    player->setPosition(visibleSize.width/2,visibleSize.height/2);
    
    
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //背景
    auto backStage = Sprite::create("onkeru/onkeru_back.jpg");
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    //downMunu
    auto downMenuBar = DownMenu::create();
    
    //Sprite* spriteO = Sprite::create("talkChara/classroom.png");
    
    this->addChild(backStage);
    
    this->addChild(player);
    
    this->addChild(downMenuBar->getDownMenu(),10);
    
    //Updateを使用する
    this->scheduleUpdate();
    //this->schedule(schedule_selector(MainGameScene::addStone),5.0f);
    //this->setDownMenu();
    
    auto dip = Director::getInstance()->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

/**画面がタップされたときの処理*/
bool MainGameScene::onTouchBegan(Touch *touch, Event *event){
    Vec2 getPoint = touch->getLocation();
    if (getPoint.x <=90) {
        getPoint.x = 90;
    }
    if(getPoint.x >= 550) {
        getPoint.x = 550;
    }
    if(getPoint.y >=490){
        getPoint.y = 490;
    }
    if(getPoint.y <= 150){
        getPoint.y = 150;
    }
    log("%f",getPoint.y);
    auto playerAction = MoveTo::create(1,Vec2(getPoint.x,getPoint.y));
    player->runAction(playerAction);
    return true;
}

/**常時呼び出される*/
void MainGameScene::update(float delta){
    PlayerData::sharePlayerData()->setNowTime();
    int elapsedTime = PlayerData::sharePlayerData()->getNowTime() - PlayerData::sharePlayerData()->getSaveTime();   //以前の時間と現在時間により経過時間
    //log("時間:%d",elapsedTime);
    if(elapsedTime >= 5){
        stoneTimeManage(elapsedTime);
    }
    for(int i=0; i< stoneArray.size(); i++){
        stoneArray[i]->Collision(player);
        if(stoneArray[i]->getState() == false){
        	stoneArray.erase(stoneArray.begin() + i);
            PlayerData::sharePlayerData()->getStoneCount++;
        }
    }
    //取得している石の取得の保存
    userDefault->setIntegerForKey("getStoneCount",PlayerData::sharePlayerData()->getStoneCount);
    userDefault->flush();
    
}

/**石を追加する*/
void MainGameScene::addStone(/*float delta*/){
    if(MAX_STONE > stoneArray.size()){
        auto stoneTest = tapClass::create("onkeru/blue.png");
        stoneTest->setPosition((rand()%500+100),(rand()%400+100));
        stoneTest->setScale(0.5);
        stoneArray.push_back(stoneTest);
        this->addChild(stoneArray.at(stoneArray.size()-1),8);
    }
    PlayerData::sharePlayerData()->downStoneCount = stoneArray.size();
    //取得している石の取得の保存
    userDefault->setIntegerForKey("downStoneCount",PlayerData::sharePlayerData()->getStoneCount);
    userDefault->flush();
}

/**時間saveTimeの初期化*/
void MainGameScene::timeInit(){
    if(PlayerData::sharePlayerData()->getSaveTime() == 0){
        PlayerData::sharePlayerData()->setSaveTime();
        log("first");
        //石の生成
        for(int i=0; i< 10; i++){
            addStone();
        }
    }
}

/**経過時間により石を操作する*/
void MainGameScene::stoneTimeManage(int elapsedTime){
    int difTime = elapsedTime / 5;
    int modTime = elapsedTime % 5;
    for(int i=0; i<difTime; i++){
        addStone();
    }
    PlayerData::sharePlayerData()->setSaveTime();
    PlayerData::sharePlayerData()->setSaveTimeMod(modTime);
    //時間の保存
    userDefault->setIntegerForKey("saveTime",PlayerData::sharePlayerData()->getSaveTime());
    userDefault->flush();
}

