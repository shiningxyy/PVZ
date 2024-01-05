#ifndef __ZOMBIENORMAL_H__
#define __ZOMBIENORMAL_H__

#include "cocos2d.h"
#include "ZombieBase.h"
USING_NS_CC;

class ZombieNormal : public ZombieBase
{
public:
    virtual bool init();
    virtual void initmove();//初始移动动画
    virtual void initattack();//初始攻击动画
    virtual void initdie();//初始死亡动画
    CREATE_FUNC(ZombieNormal);

};




#endif // __ZOMBIENORMAL_H__
