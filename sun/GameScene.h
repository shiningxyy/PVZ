
#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"
#include "ZombieNormal.h"
#include "ZombieBase.h"
#include "ZombieFlag.h"
#include "ZombieBucket.h"
#include "Car.h"
#include "MenuScene.h"
#include"sunflower.h"
#include"sunflowercard.h"
#include"SUN.h"
#include"bullet.h"
#include<vector>

USING_NS_CC;

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    SUN *sun;
    virtual bool init();
    Label* sun_num;
   

    // a selector callback
    void menuscene(cocos2d::Ref* pSender);
    CREATE_FUNC(GameScene);
};

#endif // __GAMESCENE_H__
