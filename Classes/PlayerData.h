//
//  PlayerData.h
//  testCocos
//
//  Created by OkuboTomohiro on 2015/07/18.
//
//

#ifndef __testCocos__PlayerData__
#define __testCocos__PlayerData__

class PlayerData{
private:
    PlayerData();
    static PlayerData* mPlayerData;
public:
    static PlayerData* sharePlayerData();
    //PlayerManager playermanager;
    int getStoneCount;
};

#endif /* defined(__testCocos__PlayerData__) */
