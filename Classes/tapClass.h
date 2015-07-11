//
//  tapClass.h
//  testCocos
//
//  Created by OkuboTomoihiro on 2015/06/19.
//
//

#ifndef __testCocos__tapClass__
#define __testCocos__tapClass__

#include "cocos2d.h"

class tapClass:public cocos2d::Sprite{
public:
    static tapClass* create(const char *img);
    virtual bool init(const char *img);
    void Collision(Sprite* player);
private:
    bool state;
    //void update(float delta);
};

#endif /* defined(__testCocos__tapClass__) */
