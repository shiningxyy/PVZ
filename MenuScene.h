
#ifndef __MENUSCENE_H__
#define __MENUSCENE_H__

#include "cocos2d.h"
#include "ZombieNormal.h"
#include "ZombieBase.h"
#include "ZombieFlag.h"
#include "ZombieBucket.h"
#include "Car.h"
#include "GameScene.h"
#include "GameScene2.h"

USING_NS_CC;

class MenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void gamescene(cocos2d::Ref* pSender);
    void gamescene2(cocos2d::Ref* pSender);
    void exit(Ref* pSender);

    CREATE_FUNC(MenuScene);
};

#endif // __MENUSCENE_H__
