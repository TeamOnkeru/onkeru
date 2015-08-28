//
//  StoryScene.cpp
//  testCocos
//
//  Created by 大久保友博 on 2015/08/27.
//
//

#include "StoryScene.h"
USING_NS_CC;
using namespace ui;

Scene* StoryScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StoryScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool StoryScene::init(){
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto backStage = Sprite::create("onkeru/onkeru_back.jpg");
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    
    //storyOneButton
    storyOneButton = Button::create();
    // タッチイベント True
    storyOneButton->setTouchEnabled(true);
    // ボタンの中心位置　アーカーポンイント
    storyOneButton->setAnchorPoint(Point(0.5, 0.5));
    // 通常状態の画像 押下状態の画像
    storyOneButton->loadTextures("menu/none_button.png", "menu/none_button_push.png", "menu/none_button_disable.png");
    // テキスト
    storyOneButton->setTitleText ("Story1");
    // フォント
    storyOneButton->setTitleFontName("Arial");
    storyOneButton->setTitleColor(Color3B(0,0,0));
    // フォントサイズ
    storyOneButton->setTitleFontSize(40);
    storyOneButton->setPosition(Vec2(300,visibleSize.height - 300));
    // ボタンのイベント
    storyOneButton->addTouchEventListener(this, toucheventselector(StoryScene::storyOneAction));
    
    //storyTwoButton
    storyTwoButton = Button::create();
    // タッチイベント True
    storyTwoButton->setTouchEnabled(true);
    // ボタンの中心位置　アーカーポンイント
    storyTwoButton->setAnchorPoint(Point(0.5, 0.5));
    // 通常状態の画像 押下状態の画像
    storyTwoButton->loadTextures("menu/none_button.png", "menu/none_button_push.png", "menu/none_button_disable.png");
    // テキスト
    storyTwoButton->setTitleText ("Story2");
    // フォント
    storyTwoButton->setTitleFontName("Arial");
    storyTwoButton->setTitleColor(Color3B(0,0,0));
    // フォントサイズ
    storyTwoButton->setTitleFontSize(40);
    storyTwoButton->setPosition(Vec2(300,visibleSize.height - 400));
    // ボタンのイベント
    storyTwoButton->addTouchEventListener(this, toucheventselector(StoryScene::storyTwoAction));
    
    //storyThreeButton
    storyThreeButton = Button::create();
    // タッチイベント True
    storyThreeButton->setTouchEnabled(true);
    // ボタンの中心位置　アーカーポンイント
    storyThreeButton->setAnchorPoint(Point(0.5, 0.5));
    // 通常状態の画像 押下状態の画像
    storyThreeButton->loadTextures("menu/none_button.png", "menu/none_button_push.png", "menu/none_button_disable.png");
    // テキスト
    storyThreeButton->setTitleText ("Story3");
    // フォント
    storyThreeButton->setTitleFontName("Arial");
    storyThreeButton->setTitleColor(Color3B(0,0,0));
    // フォントサイズ
    storyThreeButton->setTitleFontSize(40);
    storyThreeButton->setPosition(Vec2(300,visibleSize.height - 500));
    // ボタンのイベント
    storyThreeButton->addTouchEventListener(this, toucheventselector(StoryScene::storyThreeAction));
    
    //storyFourButton
    storyFourButton = Button::create();
    // タッチイベント True
    storyFourButton->setTouchEnabled(true);
    // ボタンの中心位置　アーカーポンイント
    storyFourButton->setAnchorPoint(Point(0.5, 0.5));
    // 通常状態の画像 押下状態の画像
    storyFourButton->loadTextures("menu/none_button.png", "menu/none_button_push.png", "menu/none_button_disable.png");
    // テキスト
    storyFourButton->setTitleText ("Story4");
    // フォント
    storyFourButton->setTitleFontName("Arial");
    storyFourButton->setTitleColor(Color3B(0,0,0));
    // フォントサイズ
    storyFourButton->setTitleFontSize(40);
    storyFourButton->setPosition(Vec2(300,visibleSize.height - 600));
    // ボタンのイベント
    storyFourButton->addTouchEventListener(this, toucheventselector(StoryScene::storyFourAction));
    
    //storyFiveButton
    storyFiveButton = Button::create();
    // タッチイベント True
    storyFiveButton->setTouchEnabled(true);
    // ボタンの中心位置　アーカーポンイント
    storyFiveButton->setAnchorPoint(Point(0.5, 0.5));
    // 通常状態の画像 押下状態の画像
    storyFiveButton->loadTextures("menu/none_button.png", "menu/none_button_push.png", "menu/none_button_disable.png");
    // テキスト
    storyFiveButton->setTitleText ("Story5");
    // フォント
    storyFiveButton->setTitleFontName("Arial");
    storyFiveButton->setTitleColor(Color3B(0,0,0));
    // フォントサイズ
    storyFiveButton->setTitleFontSize(40);
    storyFiveButton->setPosition(Vec2(300,visibleSize.height - 700));
    // ボタンのイベント
    storyFiveButton ->addTouchEventListener(this, toucheventselector(StoryScene::storyFiveAction));
    
    if(PlayerData::sharePlayerData()->getOnkeru2 == false){
        storyTwoButton->setTouchEnabled(false);
        storyTwoButton->setBright(false);
    }
    if(PlayerData::sharePlayerData()->getOnkeru3 == false){
        storyThreeButton->setTouchEnabled(false);
        storyThreeButton->setBright(false);
    }
    if(PlayerData::sharePlayerData()->getOnkeru4 == false){
        storyFourButton->setTouchEnabled(false);
        storyFourButton->setBright(false);
    }
    if(PlayerData::sharePlayerData()->getOnkeru5 == false){
        storyFiveButton->setTouchEnabled(false);
        storyFiveButton->setBright(false);
    }
    
    this->addChild(backStage);
    this->addChild(storyOneButton);
    this->addChild(storyTwoButton);
    this->addChild(storyThreeButton);
    this->addChild(storyFourButton);
    this->addChild(storyFiveButton);
    
    /*下のメニュー*/
    auto downMenuBar = DownMenu::create();
    //this->addChild(storyMenu);
    this->addChild(downMenuBar->getDownMenu());
    return true;
}

/**storyOneAction*/
void StoryScene::storyOneAction(Ref *pSender, TouchEventType type){
    switch (type)
    {
        case TOUCH_EVENT_BEGAN:
            storyOneButton->setTitleColor(Color3B(255,255,255));
            break;
        case TOUCH_EVENT_MOVED:
            break;
        case TOUCH_EVENT_ENDED:
            storyOneButton->setTitleColor(Color3B(0,0,0));
            PlayerData::sharePlayerData()->talkURL = "talkEvent/tutorial.txt";
            Director::getInstance()->replaceScene(TransitionFade::create(1.0f,talkScene::createScene()));
            //log("ここ");
            break;
        case TOUCH_EVENT_CANCELED:
            storyOneButton->setTitleColor(Color3B(0,0,0));
            break;
        default:
            break;
    }
}

/**storyTwoAction*/
void StoryScene::storyTwoAction(Ref *pSender, TouchEventType type){
    switch (type)
    {
        case TOUCH_EVENT_BEGAN:
            storyTwoButton->setTitleColor(Color3B(255,255,255));
            break;
        case TOUCH_EVENT_MOVED:
            break;
        case TOUCH_EVENT_ENDED:
            storyTwoButton->setTitleColor(Color3B(0,0,0));
            //log("ここ");
            break;
        case TOUCH_EVENT_CANCELED:
            storyTwoButton->setTitleColor(Color3B(0,0,0));
            break;
        default:
            break;
    }
}

/**storyThreeAction*/
void StoryScene::storyThreeAction(Ref *pSender, TouchEventType type){
    switch (type)
    {
        case TOUCH_EVENT_BEGAN:
            storyThreeButton->setTitleColor(Color3B(255,255,255));
            break;
        case TOUCH_EVENT_MOVED:
            break;
        case TOUCH_EVENT_ENDED:
            storyThreeButton->setTitleColor(Color3B(0,0,0));
            //log("ここ");
            break;
        case TOUCH_EVENT_CANCELED:
            storyThreeButton->setTitleColor(Color3B(0,0,0));
            break;
        default:
            break;
    }
}

/**storyFourAction*/
void StoryScene::storyFourAction(Ref *pSender, TouchEventType type){
    switch (type)
    {
        case TOUCH_EVENT_BEGAN:
            storyFourButton->setTitleColor(Color3B(255,255,255));
            break;
        case TOUCH_EVENT_MOVED:
            break;
        case TOUCH_EVENT_ENDED:
            storyFourButton->setTitleColor(Color3B(0,0,0));
            //log("ここ");
            break;
        case TOUCH_EVENT_CANCELED:
            storyFourButton->setTitleColor(Color3B(0,0,0));
            break;
        default:
            break;
    }
}

/**storyFiveAction*/
void StoryScene::storyFiveAction(Ref *pSender, TouchEventType type){
    switch (type)
    {
        case TOUCH_EVENT_BEGAN:
            storyFiveButton->setTitleColor(Color3B(255,255,255));
            break;
        case TOUCH_EVENT_MOVED:
            break;
        case TOUCH_EVENT_ENDED:
            storyFiveButton->setTitleColor(Color3B(0,0,0));
            //log("ここ");
            break;
        case TOUCH_EVENT_CANCELED:
            storyFiveButton->setTitleColor(Color3B(0,0,0));
            break;
        default:
            break;
    }
}