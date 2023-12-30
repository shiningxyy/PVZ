#ifndef __ZOMBIEBUCKET_H__
#define __ZOMBIEBUCKET_H__

#include "cocos2d.h"
#include "ZombieBase.h"
USING_NS_CC;

class ZombieBucket : public ZombieBase
{
public:
    virtual bool init();
    void initmove();
    void initattack();
    void initdie();
    virtual void update(float);
    CREATE_FUNC(ZombieBucket);

};




#endif // __ZOMBIEBUCKET_H__
