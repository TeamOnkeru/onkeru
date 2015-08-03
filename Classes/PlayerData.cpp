//
//  PlayerData.cpp
//  testCocos
//
//  Created by OkuboTomohiro on 2015/07/18.
//
//

#include "PlayerData.h"

PlayerData* PlayerData::mPlayerData = nullptr;

PlayerData::PlayerData(){
    getStoneCount =0;
    saveTime = 0;
    nowTime = 0;
    downStoneCount = 0;
}

PlayerData* PlayerData::sharePlayerData(){
    if(mPlayerData == nullptr){
        mPlayerData = new PlayerData();
    }
    return mPlayerData;
}
/**saveTimeのsetter*/
void PlayerData::setSaveTime(){
    saveTime = time(NULL);
}
/**saveTimeに差分を引く*/
void PlayerData::setSaveTimeMod(int mod){
    saveTime -= mod;
}

/**saveTimeのgetter*/
int PlayerData::getSaveTime(){
    return saveTime;
}

/**nowTimeのsetter*/
void PlayerData::setNowTime(){
    nowTime = time(NULL);
}

/**nowTimeのgetter*/
int PlayerData::getNowTime(){
    return nowTime;
}

