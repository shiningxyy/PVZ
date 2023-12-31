#ifndef __ZOMBIEBASE_H__
#define __ZOMBIEBASE_H__
#include "cocos2d.h"
USING_NS_CC;

enum ZombieType {
    zombienormal, // ∆’Õ®Ω© ¨
    zombiebucket,// Ã˙Õ∞Ω© ¨
    zombieflag //∆Ï÷ƒΩ© ¨
};

class ZombieBase : public Node
{
public:
    ZombieBase() = default;
    ~ZombieBase() = default;
    virtual bool init();
    void setstate(int);
    void setmoverate(float);
    void setrow(int);
    virtual Vec2 getposiition() const;
    virtual float getx() const;
    virtual float gety() const;
    virtual double gethp() const;
    virtual double getattack() const;
    virtual double getstate() const;
    virtual ZombieType gettype() const;
    virtual void runaction();
    void takedamagefromcar();
    void takedamagefromplant(int value);
    CREATE_FUNC(ZombieBase);

    Sprite* zombie;
    double hp;
    float moverate;
    int attack;
    int state=1;
    Vector<SpriteFrame*> moveanimFrames;
    Vector<SpriteFrame*> attackanimFrames;
    Vector<SpriteFrame*>dieanimFrames;

    ZombieType type;
    int row;
};




#endif // __ZOMBIEBASE_H__
