
#include "ZombieBase.h"
USING_NS_CC;

bool ZombieBase::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;
 }

 Vec2 ZombieBase::getposiition() const
{
	 return zombie->getPosition();
}
 float ZombieBase::getx() const
 {
	 return zombie->getPositionX();
 }
 float ZombieBase::gety() const
 {
	 return zombie->getPositionY();

 }
double ZombieBase::gethp() const
 {
	 return hp;
}
double ZombieBase::getattack() const
{
	return attack;
}
double ZombieBase::getstate() const
{
	return state;
}
void ZombieBase::setstate(int s)
{
	state = s;
}
void ZombieBase::setmoverate(float r)
{
	moverate = r;
}

void ZombieBase::setrow(int r)
{
	row = r;
}

ZombieType ZombieBase::gettype() const
{
	return type;
}

void ZombieBase::runaction()
{
	zombie->stopAllActions();
	if (state == 1) {
		Animation* animation = Animation::createWithSpriteFrames(moveanimFrames, 0.1f);
		Animate* animate = Animate::create(animation);
		zombie->runAction(RepeatForever::create(animate));
		zombie->runAction(MoveBy::create(40 / moverate, Vec2(-1024, 0)));

	}
	else if (state == 2) {
		Animation* animation = Animation::createWithSpriteFrames(attackanimFrames, 0.1f);
		Animate* animate = Animate::create(animation);
		zombie->runAction(RepeatForever::create(animate));
	}
	else if (state == 3) {
		Animation* animation = Animation::createWithSpriteFrames(dieanimFrames, 0.1f);
		Animate* animate = Animate::create(animation);
		zombie->runAction(Repeat::create(animate,1));
		zombie->runAction(Sequence::create(DelayTime::create(1.0f), Blink::create(1.0f, 5), RemoveSelf::create(), nullptr));

	}

}

void ZombieBase::takedamagefromcar()
{
	hp = 0;
}

void ZombieBase::takedamagefromplant(int value)
{
	hp =hp-value;
}
