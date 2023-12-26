
#include "ZombieNormal.h"
USING_NS_CC;

bool ZombieNormal::init()
{
	if (!Node::init())
	{
		return false;
	}
	type = zombienormal;
	hp = 100;
	attack = 10;
	moverate = 10;
	zombie = Sprite::create("NormalZombie/Move/Zombie_0.png");
	this->addChild(zombie);
	initmove();
	initattack();
	initdie();
	scheduleUpdate();
	return true;

}

void ZombieNormal::initmove()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_0.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_1.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_2.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_3.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_4.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_5.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_6.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_7.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_8.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_9.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_10.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_11.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_12.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_13.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_14.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_15.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_16.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_17.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_18.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_19.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_20.png");
	animation->addSpriteFrameWithFile("NormalZombie/Move/Zombie_21.png");
	animation->setDelayPerUnit(0.1f);
	moveaction = Animate::create(animation);
}
void ZombieNormal::initattack()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_0.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_1.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_2.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_3.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_4.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_5.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_6.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_7.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_8.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_9.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_10.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_11.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_12.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_13.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_14.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_15.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_16.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_17.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_18.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_19.png");
	animation->addSpriteFrameWithFile("NormalZombie/Attack/ZombieAttack_20.png");
	animation->setDelayPerUnit(0.1f);
	attackaction = Animate::create(animation);
}
void ZombieNormal::initdie()
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
void ZombieNormal::update(float dt)
{
	if (hp<=0) {
		state = 3;
	}
}