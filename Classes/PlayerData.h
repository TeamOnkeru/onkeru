//
//  PlayerData.h
//  testCocos
//
//  Created by OkuboTomohiro on 2015/07/18.
//
//

#ifndef __testCocos__PlayerData__
#define __testCocos__PlayerData__
#include "time.h"
#include <string>

using namespace std;

class PlayerData{
private:
    PlayerData();
    int saveTime;   //以前の時間
    int nowTime;    //現在の時間
    static PlayerData* mPlayerData;
public:
    static PlayerData* sharePlayerData();
    int getStoneCount;  //取得した石の合計
    int downStoneCount; //地面に落ちている石の合計
    int getSaveTime();  //saveTimeのgetter
    void setSaveTime();  //saveTimeのsetter
    void loadSetSaveTime(int loadSaveTime);     //引数の値をsaveTimeに代入する関数
    int getNowTime();  //nowTimeのgetter
    void setNowTime();   //nowTimeのsetter
    void setSaveTimeMod(int mod);    //余りを引く関数
    void minusStoneCount(int minusNumber);    //石を引く関数
    std::string playerChara;    //キャラクターの画像のURL
    std::string talkURL;        //会話のURL
    bool getOnkeru1;
    bool getOnkeru2;
    bool getOnkeru3;
    bool getOnkeru4;
    bool getOnkeru5;
};

#endif /* defined(__testCocos__PlayerData__) */
