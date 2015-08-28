//
//  DownMenu.h
//  testCocos
//
//  Created by 大久保友博 on 2015/07/20.
//
//

#ifndef __testCocos__DownMenu__
#define __testCocos__DownMenu__

#include "cocos2d.h"
#include "PowerStoneScene.h"
#include "MainGameScene.h"
#include "StoryScene.h"
#include "CollectionScene.h"

/**下メニュークラス*/
class DownMenu:public cocos2d::Node
{
public:
    virtual bool init();
    //下のメニュー
    cocos2d::Menu* getDownMenu();
    CREATE_FUNC(DownMenu);
    
private:
    //メニューの設定
    void setDownMenu();
    //以下ボタンの処理
    void homeButtonAction(Ref *pSender);
    void powerStoneButtonAction(Ref *pSender);
    void storyButtonAction(Ref *pSender);
    void collectionButtonAction(Ref *pSender);
    void posterButtonAction(Ref *pSender);
    
    //ボタン一つずつ
    cocos2d::MenuItemImage* homeButton;
    cocos2d::MenuItemImage* powerStoneButton;
    cocos2d::MenuItemImage* storyButton;
    cocos2d::MenuItemImage* collectionButton;
    cocos2d::MenuItemImage* posterButton;
    //downMenu
    cocos2d::Menu* downMenu;
    
};

#endif /* defined(__testCocos__DownMenu__) */
