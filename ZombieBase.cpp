
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
	 return this->getPosition();
}
 float ZombieBase::getx() const
 {
	 return this->getPositionX();
 }
 float ZombieBase::gety() const
 {
	 return this->getPositionY();

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
	if (state == 0)
		zombie->runAction(RepeatForever::create(moveaction));
	else if (state == 1) {
		zombie->runAction(RepeatForever::create(moveaction));
		zombie->runAction(MoveBy::create(40/moverate, Vec2(-100, 0)));
	}
	else if(state==2)
		zombie->runAction(RepeatForever::create(attackaction));
	else if (state == 3) {
		zombie->runAction(RepeatForever::create(dieaction));
		zombie->runAction(Sequence::create(DelayTime::create(2.0f), Blink::create(1.0f, 5), RemoveSelf::create(), nullptr));

	}

}
