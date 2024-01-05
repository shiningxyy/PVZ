
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

int ZombieBase::getrow() const
{
	return row;
}

void ZombieBase::setstate(int s)
{
	state = s;
}
void ZombieBase::setmoverate(float r)
{
	moverate = r;
}

void ZombieBase::setmovelength(int l)
{
	movelength = l;
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
	zombie->stopAllActions();//停止其他动作
	if (state == 1) {
		Animation* animation = Animation::createWithSpriteFrames(moveanimFrames, 0.1f);
		Animate* animate = Animate::create(animation);
		zombie->runAction(RepeatForever::create(animate));
		zombie->runAction(MoveTo::create(movelength/moverate, Vec2(0, row*100)));

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


void ZombieBase::initmove()
{
}

void ZombieBase::initattack()
{
}
void ZombieBase::initdie()
{
}