//
//  powerStoneScene.h
//  testCocos
//
//  Created by OkuboTomohiro on 2015/07/18.
//
//

#ifndef __testCocos__powerStoneScene__
#define __testCocos__powerStoneScene__
#include "cocos2d.h"
#include "PlayerData.h"

class PowerStoneScene : public cocos2d::Layer
{
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    CREATE_FUNC(PowerStoneScene);
private:
    
};

#endif /* defined(__testCocos__powerStoneScene__) */
