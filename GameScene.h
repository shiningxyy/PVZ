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
    std::vector<Vec2>peashooterpos;//豌豆坐标
    Vec2 plant_pos[5][9];
    void compete_plant_pos();//根据行和列计算Vec2
    bool compete_row_col(Vec2 vpos, int& row, int& col);//根据Vec2计算行和列
    double producetime;//下落阳光计时器
    double producetime2;//子弹计时器
    double producetime3;//向日葵阳光计时器
    double producetime4;//卡片冷却计时器
    std::vector<SUN*> suns;
    std::vector<Bullet*> bullets;//存子弹
    /*Bullet* b = new Bullet;
						b->sprite_init(Vec2(ppos.x, ppos.y + 10));
						this->addChild(b->bulletsprite, 66);
						b->bullet_move(); //移动到最右边
						bullets.push_back(b);
						b->bullet_explode();//爆炸动画
						b->delete_sprite();//删除精灵，不知道有什么用，先放着
						bullets.pop_back();//数组弹出子弹元素
						以下为获取数据的函数
						virtual Vec2 getposition() const; // 获取二维坐标
						virtual double getx() const; // getPositionX
						virtual double gety() const;
						virtual void set_crash(); // 设置为已撞击，
						virtual bool judge_crash(); // 返回bool is_crash; 是否碰撞的判断变量   true:碰撞  false：未碰撞
						virtual void set_attack_num(double damage);// 设置子弹伤害*/
    Label* sun_num;
};

#endif // __GAMESCENE_H__
