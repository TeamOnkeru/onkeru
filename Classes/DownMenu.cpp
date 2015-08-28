//
//  DownMenu.cpp
//  testCocos
//
//  Created by 大久保友博 on 2015/07/20.
//
//

#include "DownMenu.h"
USING_NS_CC;

bool DownMenu::init(){
    setDownMenu();
    
    return true;
}

/**下のメニューの作成*/
void DownMenu::setDownMenu(){
    /*ホームボタンの設定*/
    //auto homeButton = ui::Button::create("menu/home_button.png","menu/home_button_push.png","");
    float allPosX;
    float setPosX;
    float setPosY;
    homeButton = MenuItemImage::create("menu/home_button_new.png","menu/home_button_push_new.png",CC_CALLBACK_1(DownMenu::homeButtonAction,this));
    allPosX = homeButton->getContentSize().width;
    setPosX = allPosX/2;
    homeButton->setPosition(Vec2(setPosX,homeButton->getContentSize().height/2));
    /*パワーストーンボタン*/
    powerStoneButton = MenuItemImage::create("menu/power_stone_new.png","menu/power_stone_push_new.png",CC_CALLBACK_1(DownMenu::powerStoneButtonAction,this));
    setPosX = allPosX + powerStoneButton->getContentSize().width/2;
    setPosY = powerStoneButton->getContentSize().height/2;
    allPosX += powerStoneButton->getContentSize().width;
    powerStoneButton->setPosition(Vec2(setPosX,setPosY));
    /*ストーリーボタン*/
    storyButton = MenuItemImage::create("menu/story_button_new.png","menu/story_button_push_new.png",CC_CALLBACK_1(DownMenu::storyButtonAction,this));
    setPosX = allPosX + storyButton->getContentSize().width/2;
    allPosX += storyButton->getContentSize().width;
    storyButton->setPosition(Vec2(setPosX,setPosY));
    /*図鑑ボタン*/
    collectionButton = MenuItemImage::create("menu/collection_button_new.png","menu/collection_button_push_new.png",CC_CALLBACK_1(DownMenu::collectionButtonAction,this));
    setPosX = allPosX + collectionButton->getContentSize().width/2;
    allPosX += collectionButton->getContentSize().width;
    collectionButton->setPosition(Vec2(setPosX,setPosY));
    /*オススメボタン*/
    posterButton = MenuItemImage::create("menu/poster_button_new.png","menu/poster_button_push_new.png",CC_CALLBACK_1(DownMenu::posterButtonAction,this));
    setPosX = allPosX + posterButton->getContentSize().width/2;
    allPosX += posterButton->getContentSize().width;
    posterButton->setPosition(Vec2(setPosX,setPosY));
    
    /*メニューの作成*/
    downMenu = Menu::create(homeButton, powerStoneButton, storyButton, collectionButton, posterButton, NULL);
    downMenu->setAnchorPoint(Vec2(1,0));   //座標軸を左上にする
    log("test:%f",homeButton->getContentSize().height);
    downMenu->setPosition(Vec2(0,0));
    //this->addChild(downMenu,10);
}

Menu* DownMenu::getDownMenu(){
    return downMenu;
}

void DownMenu::homeButtonAction(Ref *pSender){
    log("Home");
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f,MainGameScene::createScene()));
}
void DownMenu::powerStoneButtonAction(Ref *pSender){
    log("PowerStone");
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f,PowerStoneScene::createScene()));
}
void DownMenu::storyButtonAction(Ref *pSender){
    log("storyButton");
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f,StoryScene::createScene()));
}
void DownMenu::collectionButtonAction(Ref *pSender){
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f,CollectionScene::createScene()));
    log("collectionButton");
}
void DownMenu::posterButtonAction(Ref *pSender){
    log("PosterButton");
}
