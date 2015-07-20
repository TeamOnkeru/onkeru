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
    
    //表示する文字列
    auto drawLabel = Label::createWithSystemFont("","fonts/NotoSansCJKjp-Regular.otf",30);
    drawLabel->setColor(Color3B(255,255,255));
    drawLabel->setString(StringUtils::toString(PlayerData::sharePlayerData()->getStoneCount).c_str());
    drawLabel->setPosition(visibleSize.width/2,visibleSize.height/2);
    
    //下のメニュー
    auto downMenuBar = DownMenu::create();
    this->addChild(drawLabel);
    this->addChild(downMenuBar->getDownMenu());
    
    return true;
}