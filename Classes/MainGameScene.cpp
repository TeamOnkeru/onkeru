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
    Size visibleSize = Director::getInstance()->getVisibleSize();
    /**タッチ処理*/
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(MainGameScene::onTouchBegan,this);
    
    player = Sprite::create("onkeru/player_mock.png");
    player->setScale(0.5);
    player->setPosition(visibleSize.width/2,visibleSize.height/2);
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //背景
    auto backStage = Sprite::create("talkChara/classroom.png");
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    //Sprite* spriteO = Sprite::create("talkChara/classroom.png");
    
    //石のテスト
    stoneTest = tapClass::create("onkeru/blue.png");
    stoneTest->setPosition(300,100);
    stoneTest->setScale(0.5);
    
    this->addChild(backStage);
    this->addChild(stoneTest);
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
    stoneTest->Collision(player);
    /*
    if(stoneTest->Collision(player) == true){
        this->removeChild(stoneTest);
    }*/
}

