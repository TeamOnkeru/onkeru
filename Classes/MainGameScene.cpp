//
//  MainGameScene.cpp
//  testCocos
//
//  Created by 大久保友博 on 2015/07/10.
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
    //std::vector<tapClass*> stoneArray;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    /**タッチ処理*/
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(MainGameScene::onTouchBegan,this);
    
    //"onkeru/player_mock.png"
    player = Sprite::create("onkeru/player_mock.png");
    player->setScale(0.5);
    player->setPosition(visibleSize.width/2,visibleSize.height/2);
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //背景
    //"talkChara/classroom.png"
    auto backStage = Sprite::create("talkChara/classroom.png");
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    //Sprite* spriteO = Sprite::create("talkChara/classroom.png");
    
    //石のテスト
    //"onkeru/blue.png"
    for(int i=0; i< 10; i++){
        stoneTest = tapClass::create("onkeru/blue.png");
        stoneTest->setPosition((rand()%400+100),(rand()%400+100));
        stoneTest->setScale(0.5);
        stoneArray.push_back(stoneTest);
    }
    
    this->addChild(backStage);
    for(int i=0; i<10; i++){
        this->addChild(stoneArray[i]);
    }
    //this->addChild(stoneTest);
    
    this->addChild(player);
    
    //Updateを使用する
    this->scheduleUpdate();
    
    auto dip = Director::getInstance()->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

bool MainGameScene::onTouchBegan(Touch *touch, Event *event){
    Vec2 getPoint = touch->getLocation();
    log("%f",getPoint.y);
    auto playerAction = MoveTo::create(1,Vec2(getPoint.x,getPoint.y));
    player->runAction(playerAction);
    return true;
}

void MainGameScene::update(float delta){
    for(int i=0; i< stoneArray.size(); i++){
        stoneArray[i]->Collision(player);
        if(stoneArray[i]->getState() == false){
        	stoneArray.erase(stoneArray.begin() + i);
        	//log("aaaa");
        }
        //stoneTest->Collision(player);
    }
    /*
    if(stoneTest->Collision(player) == true){
        this->removeChild(stoneTest);
    }*/
}

