
#include "ZombieFlag.h"
USING_NS_CC;

bool ZombieFlag::init()
{
	if (!Node::init())
	{
		return false;
	}
	type = zombieflag;
	hp = 100;
	attack = 10;
	moverate = 15;
	zombie = Sprite::create("FlagZombie/Move/Zombie_0.png");
	this->addChild(zombie);
	initmove();
	initattack();
	initdie();
	scheduleUpdate();
	return true;

}

void ZombieFlag::initmove()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_0.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_1.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_2.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_3.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_4.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_5.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_6.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_7.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_8.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_9.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_10.png");
	animation->addSpriteFrameWithFile("FlagZombie/Move/Zombie_11.png");
	animation->setDelayPerUnit(0.08f);
	moveaction = Animate::create(animation);
}
void ZombieFlag::initattack()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_0.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_1.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_2.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_3.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_4.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_5.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_6.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_7.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_8.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_9.png");
	animation->addSpriteFrameWithFile("FlagZombie/Attack/ZombieAttack_10.png");
	animation->setDelayPerUnit(0.1f);
	attackaction = Animate::create(animation);
}
void ZombieFlag::initdie()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("NormalZombie/Die/01.png");
	animation->addSpriteFrameWithFile("NormalZombie/Die/01.png");
	animation->addSpriteFrameWithFile("NormalZombie/Die/02.png");
	animation->addSpriteFrameWithFile("NormalZombie/Die/03.png");
	animation->addSpriteFrameWithFile("NormalZombie/Die/04.png");
	animation->addSpriteFrameWithFile("NormalZombie/Die/05.png");
	animation->addSpriteFrameWithFile("NormalZombie/Die/06.png");
	animation->addSpriteFrameWithFile("NormalZombie/Die/07.png");
	animation->addSpriteFrameWithFile("NormalZombie/Die/08.png");
	animation->addSpriteFrameWithFile("NormalZombie/Die/09.png");
	animation->setDelayPerUnit(0.2f);
	dieaction = Animate::create(animation);
}
void ZombieFlag::update(float dt)
{
	if (hp <= 0) {
		state = 3;
	}
}