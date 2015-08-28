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
    getStoneCount =0;   //所持している石の数
    saveTime = 0;
    nowTime = 0;
    downStoneCount = 0;
    playerChara = "onkeru/player_normal.png";
    getOnkeru1 = true;
    getOnkeru2 = false;
    getOnkeru3 = false;
    getOnkeru4 = false;
    getOnkeru5 = false;
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

/**saveTimeに保存していた値を代入する*/
void PlayerData::loadSetSaveTime(int loadSaveTime){
    saveTime = loadSaveTime;
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

/**Stoneを引くための関数
 *@param minusNumber:引く石の数
 */
void PlayerData::minusStoneCount(int minusNumber){
    getStoneCount -= minusNumber;
}
