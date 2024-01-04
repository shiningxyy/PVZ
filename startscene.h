
#ifndef __STARTSCENE_H__
#define __STARTSCENE_H__

#include "cocos2d.h"
#include "ZombieNormal.h"
#include "ZombieBase.h"
#include "ZombieFlag.h"
#include "ZombieBucket.h"
#include "Car.h"
#include "GameScene.h"

USING_NS_CC;

class StartScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void manuscene(cocos2d::Ref* pSender);


    CREATE_FUNC(StartScene);
};

#endif // __LOSESCENE_H__