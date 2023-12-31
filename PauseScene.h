#pragma once
#ifndef __MENUSCENE_H__
#define __MENUSCENE_H__

#include"plant.h"
#include"sunflower.h"
#include"peashooter.h"
#include"wallnut.h"
#include"cherrybomb.h"
#include"card.h"
#include"sunflowercard.h"
#include"peashootercard.h"
#include"wallnutcard.h"
#include"cherrybombcard.h"
#include"AudioEngine.h"
#include "ui/CocosGUI.h"
#include<vector>
USING_NS_CC;
class PauseScene :public  cocos2d::Scene {
public:
	static cocos2d::Scene* createScene() { return PauseScene::create(); };
	virtual bool init();
	void menuCloseCallback(Ref* pSender);
	CREATE_FUNC(PauseScene);
};
#endif // __MENUSCENE_H__