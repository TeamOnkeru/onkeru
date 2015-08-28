//
//  CollectionScene.h
//  testCocos
//
//  Created by 大久保友博 on 2015/08/24.
//
//

#ifndef __testCocos__CollectionScene__
#define __testCocos__CollectionScene__

#include "cocos2d.h"
#include "PlayerData.h"
#include "DownMenu.h"

class CollectionScene : public cocos2d::Layer
{
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    CREATE_FUNC(CollectionScene);
private:
    
};

#endif /* defined(__testCocos__CollectionScene__) */
