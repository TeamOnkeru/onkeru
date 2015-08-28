//
//  CollectionScene.cpp
//  testCocos
//
//  Created by 大久保友博 on 2015/08/24.
//
//

#include "CollectionScene.h"
USING_NS_CC;

Scene* CollectionScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CollectionScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool CollectionScene::init(){
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto backStage = Sprite::create("onkeru/onkeru_back.jpg");
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    
    auto onkeruOneBack = Sprite::create();
    onkeruOneBack->setTextureRect(Rect(0,0,200,200));
    onkeruOneBack->setColor(Color3B(200,200,100));
    onkeruOneBack->setPosition(Vec2(150,visibleSize.height-150));
    
    auto onkeruTwoBack = Sprite::create();
    onkeruTwoBack->setTextureRect(Rect(0,0,200,200));
    onkeruTwoBack->setColor(Color3B(200,200,100));
    onkeruTwoBack->setPosition(Vec2(500,visibleSize.height-150));
    
    auto onkeruThreeBack = Sprite::create();
    onkeruThreeBack->setTextureRect(Rect(0,0,200,200));
    onkeruThreeBack->setColor(Color3B(200,200,100));
    onkeruThreeBack->setPosition(Vec2(150,visibleSize.height-400));
    
    auto onkeruFourBack = Sprite::create();
    onkeruFourBack->setTextureRect(Rect(0,0,200,200));
    onkeruFourBack->setColor(Color3B(200,200,100));
    onkeruFourBack->setPosition(Vec2(500,visibleSize.height-400));
    
    auto onkeruFiveBack = Sprite::create();
    onkeruFiveBack->setTextureRect(Rect(0,0,200,200));
    onkeruFiveBack->setColor(Color3B(200,200,100));
    onkeruFiveBack->setPosition(Vec2(150,visibleSize.height-650));
    
    //表示するキャラクタ−1
    auto onkeruOne = Sprite::create("onkeru/player_normal.png");
    onkeruOne->setPosition(Vec2(150,visibleSize.height-150));
    //表示するキャラクタ−2
    auto onkeruTwo = Sprite::create("onkeru/player_mobu.png");
    onkeruTwo->setPosition(Vec2(500,visibleSize.height-150));
    //表示するキャラクタ−3
    auto onkeruThree = Sprite::create("onkeru/player_potya.png");
    onkeruThree->setPosition(Vec2(150,visibleSize.height-400));
    //表示するキャラクタ−4
    auto onkeruFour = Sprite::create("onkeru/player_smile.png");
    onkeruFour->setPosition(Vec2(500,visibleSize.height-400));
    //表示するキャラクタ−5
    auto onkeruFive = Sprite::create("onkeru/player_zuru.png");
    onkeruFive->setPosition(Vec2(150,visibleSize.height-650));
    
    if(PlayerData::sharePlayerData()->getOnkeru2 == false){
        onkeruTwo->setColor(Color3B(0,0,0));
    }
    
    if(PlayerData::sharePlayerData()->getOnkeru3 == false){
        onkeruThree->setColor(Color3B(0,0,0));
    }
    if(PlayerData::sharePlayerData()->getOnkeru4 == false){
        onkeruFour->setColor(Color3B(0,0,0));
    }
    if(PlayerData::sharePlayerData()->getOnkeru5 == false){
        onkeruFive->setColor(Color3B(0,0,0));
    }
    
    this->addChild(backStage);
    
    this->addChild(onkeruOneBack);
    this->addChild(onkeruTwoBack);
    this->addChild(onkeruThreeBack);
    this->addChild(onkeruFourBack);
    this->addChild(onkeruFiveBack);
    //キャラクター
    this->addChild(onkeruOne);
    this->addChild(onkeruTwo);
    this->addChild(onkeruThree);
    this->addChild(onkeruFour);
    this->addChild(onkeruFive);
    
    /*下のメニュー*/
    auto downMenuBar = DownMenu::create();
    //this->addChild(storyMenu);
    this->addChild(downMenuBar->getDownMenu());
    
    return true;
}