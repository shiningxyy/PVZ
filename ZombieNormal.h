#ifndef __ZOMBIENORMAL_H__
#define __ZOMBIENORMAL_H__

#include "cocos2d.h"
#include "ZombieBase.h"
USING_NS_CC;

class ZombieNormal : public ZombieBase
{
public:
    virtual bool init();
    void initmove();
    void initattack();
    void initdie();
    CREATE_FUNC(ZombieNormal);

};




#endif // __ZOMBIENORMAL_H__
