#pragma once
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
#include "WinScene.h"
#include "LoseScene.h"
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
#include"SUN.h"
#include"bullet.h"
USING_NS_CC;

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
  
    virtual bool init();
    virtual void update(float);
    // a selector callback
    void menuscene(cocos2d::Ref* pSender);
    void createcar();
    void  createplant();
    Vector<ZombieBase*> zombienumber;//用于保存已经创建的僵尸
    Vector<Car*> carnumber;//保存汽车
    
    CREATE_FUNC(GameScene);
    int gametime = 0;
    void createzombie();
    ZombieBase* get_row_left_zombie(int row_);

    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    void plant(int row, int col, PlantType t);
    Sprite* mouse_s;
    PlantType ptype;
    // a selector callback
   
    void menuCloseCallback(Ref* pSender);
  
    std::vector<Card*>cards;
    std::vector<Plant*>plants;
    std::vector<Car*>cars;
    std::vector<Vec2>sunflowerpos;//向日葵坐标
    std::vector<Vec2>peashooterpos;
    Vec2 plant_pos[5][9];
    void compete_plant_pos();//根据行和列计算Vec2
    bool compete_row_col(Vec2 vpos, int& row, int& col);//根据Vec2计算行和列
    double producetime;
    std::vector<SUN*> suns;
    Label* sun_num;
};

#endif // __GAMESCENE_H__
