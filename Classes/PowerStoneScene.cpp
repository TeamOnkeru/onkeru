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
    
    //背景
    auto backStage = Sprite::create("onkeru/divination.png");
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    
    //表示する文字列
    auto drawLabel = Label::createWithSystemFont("","fonts/NotoSansCJKjp-Regular.otf",30);
    drawLabel->setColor(Color3B(255,255,255));
    std::string drawStoneLabel("パワーストーン:");
    drawStoneLabel.append(StringUtils::toString(PlayerData::sharePlayerData()->getStoneCount).c_str());
    drawStoneLabel.append("個");
    
    drawLabel->setString(drawStoneLabel);
    drawLabel->setPosition(visibleSize.width/2,visibleSize.height/2-visibleSize.height/5);
    
    //下のメニュー
    auto downMenuBar = DownMenu::create();
    this->addChild(backStage);
    this->addChild(drawLabel);
    this->addChild(downMenuBar->getDownMenu());
    
    return true;
}