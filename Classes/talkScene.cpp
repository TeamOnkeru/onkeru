//
//  talkScene.cpp
//  testCocos
//
//  Created by OkuboTomoihiro on 2015/06/28.
//
//

#include "talkScene.h"
USING_NS_CC;

Scene* talkScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = talkScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool talkScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //画面サイズ
    Size visibleSize = Director::getInstance()->getVisibleSize();
    //背景
    backStage = Sprite::create("onkeru/onkeru_back.jpg");
    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
    //右側のキャラクター
    rightChara = Sprite::create();
    rightChara->setPosition(500,530);
    rightChara->setScale(0.8f);
    //左側のキャラクター
    leftChara = Sprite::create();
    leftChara->setPosition(150,530);
    leftChara->setScale(0.8f);

    //会話表示
    Sprite* talkBox = Sprite::create();
    talkBox->setTextureRect(Rect(0, 0, visibleSize.width, 300));
    talkBox->setColor(Color3B(242, 216, 223));
    talkBox->setPosition(visibleSize.width/2,talkBox->getContentSize().height/2);
    
    //名前の文字
    nameLabel = Label::createWithSystemFont("","fonts/NotoSansCJKjp-Regular.otf",30);
    nameLabel->setColor(Color3B(0,0,0));
    nameLabel->setPosition(20,talkBox->getPositionY()*2+20+40);
    nameLabel->setAnchorPoint(Vec2(0.0f,1.0f));
    //表示する文字をdrawに読み込むフラグ
    readFlag = true;
    drawLabelCount = 0;
    
    //クリック処理
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(talkScene::onTouchBegan,this);
    
    //表示する文字列
    drawLabel = Label::createWithSystemFont("","fonts/NotoSansCJKjp-Regular.otf",30);
    drawLabel->setColor(Color3B(0,0,0));
    drawLabel->setAnchorPoint(Vec2(0,1));   //座標軸を左上にする
    drawLabel->setPosition(20,talkBox->getPositionY()*2-10);
    drawLabel->setWidth(600);
    
    
    this->addChild(backStage);
    this->addChild(rightChara);
    this->addChild(leftChara);
    this->addChild(talkBox);
    
    /*
    for(int i=0; i<7;i++){
        this->addChild(drawLabel[i]);
    }*/
    this->addChild(drawLabel);
    this->addChild(nameLabel);
    readText(PlayerData::sharePlayerData()->talkURL);
    this->scheduleUpdate();
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

/**指定された文字でカットする関数
 @param input:カットする文字列
 @param delmiter:カットにしようする一文字
 @return カットしたものをstd::vectorで返す
 */
std::vector<std::string> talkScene::split(const std::string& input, char delimiter) {
    std::istringstream stream(input);
    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
};

/**テキストを読み込み関数
 *@param fileName:読み込むファイル名
 */
void talkScene::readText(std::string fileName){
    std::string fileText =  FileUtils::getInstance()->getStringFromFile(fileName);
    auto lines = split(fileText, '\n');
    for (const auto& line : lines) {
        // ここに処理を記述
        auto stack = split(line,'@');
        readTextData.push_back(stack);
    }
    
    log("%s",readTextData.at(0).at(1).c_str());
    
    
}
/**アップデート関数*/
void talkScene::update(float delta){
    //log("a");
    if(readFlag == true){
        readTextToDrawObject(readTextData[drawLabelCount][0]);
        
    }
}

/**クリックが離れたら*/
bool talkScene::onTouchBegan(Touch *touch,Event * event){
    if(readFlag == false){
        drawLabelCount ++;
        readFlag = true;
        drawLabel->setString("");
    }
    return true;
}

/**読み込んだ文字列の指示に従いオブジェクトを表示する
 *@param flag:読み込んだ文字の指示部
 */
void talkScene::readTextToDrawObject(std::string flag){
    if(readFlag == true){
        std::string content = readTextData[drawLabelCount][1];
        //log("%s",flag.c_str());
        if(flag == "S"){
            std::string stackString = drawLabel->getString()+"\n"+content;
            drawLabel->setString(stackString.c_str());
            readFlag = false;
        }else{
            if(flag == "SetStage"){
                //log("%s",readTextData[drawLabelCount][1].c_str());
                if(content == "IN"){
                    backStage->setTexture("onkeru/divination.png");
                    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
                }
                if(content == "OUT"){
                    backStage->setTexture("onkeru/onkeru_back.jpg");
                    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
                }
                /*
                if(content == "passage"){
                    log("koko");
                    backStage->setTexture("talkChara/classroom.png");
                    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
                }
                if(content == "pcroom"){
                    backStage->setTexture("talkChara/audiovisualroom.png");
                    backStage->setPosition(backStage->getContentSize().width/2,backStage->getContentSize().height/2);
                }*/
            }else if(flag == "SLC"){
                if(content == "OBA"){
                    leftChara->setTexture("onkeru/oba.png");
                }
                if(content == "PLAYER"){
                    leftChara->setTexture(PlayerData::sharePlayerData()->playerChara);
                }
                /*
                if(content=="LISA"){
                    leftChara->setTexture("talkChara/lisa_smile.png");
                }
                if(content == "FURUICHI"){
                    leftChara->setTexture("talkChara/fruichi.png");
                }
                if(content == "LENNON"){
                    leftChara->setTexture("talkChara/lennon_normal.png");
                }*/
            }else if(flag == "SRC"){
                if(content == "OBA"){
                    rightChara->setTexture("onkeru/oba.png");
                }
                if(content == "PLAYER"){
                    rightChara->setTexture(PlayerData::sharePlayerData()->playerChara);
                }
                /*
                if(content=="LISA"){
                    rightChara->setTexture("talkChara/lisa_smile.png");
                }
                if(content == "FURUICHI"){
                    rightChara->setTexture("talkChara/fruichi.png");
                }
                if(content == "LENNON"){
                    rightChara->setTexture("talkChara/lennon_normal.png");
                }*/
            }else if(flag == "N"){
                nameLabel->setString(content);
            }else if(flag ==""){
                std::string stackString = drawLabel->getString()+"\n"+content;
                drawLabel->setString(stackString.c_str());
            }else if(flag == "Talk"){
                if(content == "R"){
                    leftChara->setColor(Color3B(100,100,100));
                    rightChara->setColor(Color3B(255,255,255));
                }
                if(content == "L"){
                    rightChara->setColor(Color3B(100,100,100));
                    leftChara->setColor(Color3B(255,255,255));
                }
            }
            else if(flag == "END"){
                Director::getInstance()->replaceScene(TransitionFade::create(1.0f,MainGameScene::createScene()));
            }
            drawLabelCount++;
        }
    }
}