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
    //std::string getStone = PlayerData::sharePlayerData()->getStoneCount;
    auto drawLabel = Label::createWithSystemFont("aaa","fonts/NotoSansCJKjp-Regular.otf",30);
    drawLabel->setColor(Color3B(255,255,255));
    drawLabel->setString(StringUtils::toString(PlayerData::sharePlayerData()->getStoneCount).c_str());
    //drawLabel->setAnchorPoint(Vec2(0,1));   //座標軸を左上にする
    drawLabel->setPosition(visibleSize.width/2,visibleSize.height/2);
    //drawLabel->setWidth(600);
    this->addChild(drawLabel);
    
    return true;
}