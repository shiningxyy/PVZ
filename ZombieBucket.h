#ifndef __ZOMBIEBUCKET_H__
#define __ZOMBIEBUCKET_H__

#include "cocos2d.h"
#include "ZombieBase.h"
USING_NS_CC;

class ZombieBucket : public ZombieBase
{
public:
    virtual bool init();
    virtual void initmove();//初始移动动画
    virtual void initattack();//初始攻击动画
    virtual void initdie();//初始死亡动画
    CREATE_FUNC(ZombieBucket);

};




#endif // __ZOMBIEBUCKET_H__
