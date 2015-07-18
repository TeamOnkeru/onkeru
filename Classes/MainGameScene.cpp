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
    auto backStage = Sprite::create("onkeru/backstage.png");
    //backStage->setScale(0.5);
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    
    
    //Sprite* spriteO = Sprite::create("talkChara/classroom.png");
    
    //石のテスト
    //"onkeru/blue.png"
    for(int i=0; i< 10; i++){
        auto stoneTest = tapClass::create("onkeru/blue.png");
        stoneTest->setPosition((rand()%500+100),(rand()%500+100));
        stoneTest->setScale(0.5);
        stoneArray.push_back(stoneTest);
    }
    
    this->addChild(backStage);
    for(int i=0; i<stoneArray.size(); i++){
        this->addChild(stoneArray[i]);
    }
    //this->addChild(stoneTest);
    
    this->addChild(player);
    
    //Updateを使用する
    this->scheduleUpdate();
    this->schedule(schedule_selector(MainGameScene::addStone),5.0f);
    this->setDownMenu();
    auto dip = Director::getInstance()->getEventDispatcher();
    dip->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

/**画面がタップされたときの処理*/
bool MainGameScene::onTouchBegan(Touch *touch, Event *event){
    Vec2 getPoint = touch->getLocation();
    log("%f",getPoint.y);
    auto playerAction = MoveTo::create(1,Vec2(getPoint.x,getPoint.y));
    player->runAction(playerAction);
    return true;
}
/**常時呼び出される*/
void MainGameScene::update(float delta){
    for(int i=0; i< stoneArray.size(); i++){
        stoneArray[i]->Collision(player);
        if(stoneArray[i]->getState() == false){
        	stoneArray.erase(stoneArray.begin() + i);
            PlayerData::sharePlayerData()->getStoneCount++;
        }
    }
    log("stone:%d",PlayerData::sharePlayerData()->getStoneCount);
}
/**石を追加する*/
void MainGameScene::addStone(float delta){
    auto stoneTest = tapClass::create("onkeru/blue.png");
    stoneTest->setPosition((rand()%500+100),(rand()%500+100));
    stoneTest->setScale(0.5);
    stoneArray.push_back(stoneTest);
    this->addChild(stoneArray.at(stoneArray.size()-1));
}

/**下のメニューの作成*/
void MainGameScene::setDownMenu(){
    /*ホームボタンの設定*/
    //auto homeButton = ui::Button::create("menu/home_button.png","menu/home_button_push.png","");
    float allPosX;
    float setPosX;
    float setPosY;
    auto homeButton = MenuItemImage::create("menu/home_button_new.png","menu/home_button_push_new.png",CC_CALLBACK_1(MainGameScene::homeButtonAction,this));
    allPosX = homeButton->getContentSize().width;
    setPosX = allPosX/2;
    homeButton->setPosition(Vec2(setPosX,homeButton->getContentSize().height/2));
    /*パワーストーンボタン*/
    auto powerStoneButton = MenuItemImage::create("menu/power_stone_new.png","menu/power_stone_push_new.png",CC_CALLBACK_1(MainGameScene::powerStoneButtonAction,this));
    setPosX = allPosX + powerStoneButton->getContentSize().width/2;
    setPosY = powerStoneButton->getContentSize().height/2;
    allPosX += powerStoneButton->getContentSize().width;
    powerStoneButton->setPosition(Vec2(setPosX,setPosY));
    /*ストーリーボタン*/
    auto storyButton = MenuItemImage::create("menu/story_button_new.png","menu/story_button_push_new.png",CC_CALLBACK_1(MainGameScene::storyButtonAction,this));
    setPosX = allPosX + storyButton->getContentSize().width/2;
    allPosX += storyButton->getContentSize().width;
    storyButton->setPosition(Vec2(setPosX,setPosY));
    /*図鑑ボタン*/
    auto collectionButton = MenuItemImage::create("menu/collection_button_new.png","menu/collection_button_push_new.png",CC_CALLBACK_1(MainGameScene::collectionButtonAction,this));
    setPosX = allPosX + collectionButton->getContentSize().width/2;
    allPosX += collectionButton->getContentSize().width;
    collectionButton->setPosition(Vec2(setPosX,setPosY));
    /*オススメボタン*/
    auto posterButton = MenuItemImage::create("menu/poster_button_new.png","menu/poster_button_push_new.png",CC_CALLBACK_1(MainGameScene::posterButtonAction,this));
    setPosX = allPosX + posterButton->getContentSize().width/2;
    allPosX += posterButton->getContentSize().width;
    posterButton->setPosition(Vec2(setPosX,setPosY));
    
    /*メニューの作成*/
    auto downMenu = Menu::create(homeButton, powerStoneButton, storyButton, collectionButton, posterButton, NULL);
    downMenu->setAnchorPoint(Vec2(1,0));   //座標軸を左上にする
    log("test:%f",homeButton->getContentSize().height);
    downMenu->setPosition(Vec2(0,0));
    this->addChild(downMenu,10);
}

void MainGameScene::homeButtonAction(Ref *pSender){
    log("Home");
}
void MainGameScene::powerStoneButtonAction(Ref *pSender){
    log("PowerStone");
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f,PowerStoneScene::createScene()));
}
void MainGameScene::storyButtonAction(Ref *pSender){
    log("storyButton");
}
void MainGameScene::collectionButtonAction(Ref *pSender){
    log("collectionButton");
}
void MainGameScene::posterButtonAction(Ref *pSender){
    log("PosterButton");
}

