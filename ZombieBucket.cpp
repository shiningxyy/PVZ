
#include "ZombieBucket.h"
USING_NS_CC;

bool ZombieBucket::init()
{
	if (!Node::init())
	{
		return false;
	}
	type = zombiebucket;
	hp = 150;
	attack = 10;
	moverate = 10;
	zombie = Sprite::create("BucketZombie/Move/Zombie_0.png");
	this->addChild(zombie);
	initmove();
	initattack();
	initdie();
	scheduleUpdate();
	return true;

}

void ZombieBucket::initmove()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_0.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_1.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_2.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_3.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_4.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_5.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_6.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_7.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_8.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_9.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_10.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_11.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_12.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_13.png");
	animation->addSpriteFrameWithFile("BucketZombie/Move/Zombie_14.png");
	animation->setDelayPerUnit(0.1f);
	moveaction = Animate::create(animation);
}
void ZombieBucket::initattack()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_0.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_1.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_2.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_3.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_4.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_5.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_6.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_7.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_8.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_9.png");
	animation->addSpriteFrameWithFile("BucketZombie/Attack/ZombieAttack_10.png");
	animation->setDelayPerUnit(0.1f);
	attackaction = Animate::create(animation);
}
void ZombieBucket::initdie()
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
void ZombieBucket::update(float dt)
{
	if (hp <= 0) {
		state = 3;
	}
}