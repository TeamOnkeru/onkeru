//
//  StoryScene.h
//  testCocos
//
//  Created by 大久保友博 on 2015/08/27.
//
//

#ifndef __testCocos__StoryScene__
#define __testCocos__StoryScene__

#include "cocos2d.h"
#include "PlayerData.h"
#include "DownMenu.h"
#include "talkScene.h"
#include <ui/CocosGUI.h>

class StoryScene : public cocos2d::Layer
{
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    CREATE_FUNC(StoryScene);
private:
    /*
    cocos2d::MenuItemImage* storyOneButton;
    cocos2d::MenuItemImage* storyTwoButton;
    cocos2d::MenuItemImage* storyThreeButton;
    cocos2d::MenuItemImage* storyFourButton;
    cocos2d::MenuItemImage* storyFIveButton;
    cocos2d::Menu* storyMenu;
    */
    void storyOneAction(Ref *pSender, cocos2d::ui::TouchEventType type);
    void storyTwoAction(Ref *pSender, cocos2d::ui::TouchEventType type);
    void storyThreeAction(Ref *pSender, cocos2d::ui::TouchEventType type);
    void storyFourAction(Ref *pSender, cocos2d::ui::TouchEventType type);
    void storyFiveAction(Ref *pSender, cocos2d::ui::TouchEventType type);
    
    cocos2d::ui::Button* storyOneButton;
    cocos2d::ui::Button* storyTwoButton;
    cocos2d::ui::Button* storyThreeButton;
    cocos2d::ui::Button* storyFourButton;
    cocos2d::ui::Button* storyFiveButton;
};

#endif /* defined(__testCocos__StoryScene__) */
