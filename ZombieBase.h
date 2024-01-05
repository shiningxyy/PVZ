#ifndef __ZOMBIEBASE_H__
#define __ZOMBIEBASE_H__
#include "cocos2d.h"
USING_NS_CC;

enum ZombieType {
    zombienormal, // 普通僵尸
    zombiebucket,// 铁桶僵尸
    zombieflag //旗帜僵尸
};

class ZombieBase : public Node
{
public:
    ZombieBase() = default;
    ~ZombieBase() = default;
    virtual bool init();//初始化
    void setstate(int);//设置状态
    void setmoverate(float);//设置移动速度
    void setrow(int);//设置行
    void setmovelength(int);//设置移动长度
     Vec2 getposiition() const;//返回vec2坐标
     float getx() const;//返回x
     float gety() const;//返回y
     double gethp() const;//返回生命值
     double getattack() const;//返回攻击值
     double getstate() const;//返回状态
     int getrow() const;//返回行
    virtual ZombieType gettype() const;//返回僵尸类型
     void runaction();//播放动画
    void takedamagefromcar();//受到伤害（小车
    void takedamagefromplant(int value);//受到伤害（植物
    virtual void initmove();//初始移动动画
    virtual void initattack();//初始攻击动画
    virtual void initdie();//初始死亡动画
    CREATE_FUNC(ZombieBase);

    Sprite* zombie;//精灵
    double hp;//生命值
    float moverate;//移动速度
    float movetime;//移动时间
    int movelength;//移动长度
    int attack;//攻击值
    int state=1;//状态 1：移动  2；攻击  3；死亡
    Vector<SpriteFrame*> moveanimFrames;//移动动画帧
    Vector<SpriteFrame*> attackanimFrames;//攻击动画帧
    Vector<SpriteFrame*>dieanimFrames;//死亡动画帧

    ZombieType type;//僵尸类型
    int row;//行
};




#endif // __ZOMBIEBASE_H__
