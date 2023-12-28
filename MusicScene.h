
#ifndef __MUSICSCENE_H__
#define __MUSICSCENE_H__

#include "cocos2d.h"
#include "ZombieNormal.h"
#include "ZombieBase.h"
#include "ZombieFlag.h"
#include "ZombieBucket.h"
#include "Car.h"
#include "MenuScene.h"

USING_NS_CC;

class MusicScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuscene(cocos2d::Ref* pSender);
    CREATE_FUNC(MusicScene);
};

#endif // __MUSICSCENE_H__
