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
}

PlayerData* PlayerData::sharePlayerData(){
    if(mPlayerData == nullptr){
        mPlayerData = new PlayerData();
    }
    return mPlayerData;
}