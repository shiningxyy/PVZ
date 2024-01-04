#ifndef __ZOMBIEFLAG_H__
#define __ZOMBIEFLAG_H__

#include "cocos2d.h"
#include "ZombieBase.h"
USING_NS_CC;

class ZombieFlag : public ZombieBase
{
public:
    virtual bool init();
    void initmove();
    void initattack();
    void initdie();
    CREATE_FUNC(ZombieFlag);

};




#endif // __ZOMBIEFLAG_H__
