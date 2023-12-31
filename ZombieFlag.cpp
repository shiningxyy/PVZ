
#include "ZombieFlag.h"
USING_NS_CC;

bool ZombieFlag::init()
{
	if (!Node::init())
	{
		return false;
	}
	type = zombienormal;
	hp = 100;
	attack = 10;
	moverate = 15;
	zombie = Sprite::create("FlagZombie/Move/Zombie_0.png");
	this->addChild(zombie);
	initmove();
	initattack();
	initdie();
	this->scheduleUpdate();
	return true;

}

void ZombieFlag::initmove()
{
	moveanimFrames.reserve(12);
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_0.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_1.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_2.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_3.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_4.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_5.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_6.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_7.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_8.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_9.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_10.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_11.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("FlagZombie/Move/Zombie_12.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
}
void ZombieFlag::initattack()
{
	attackanimFrames.reserve(11);
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_0.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_1.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_2.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_3.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_4.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_5.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_6.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_7.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_8.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_9.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("FlagZombie/Attack/ZombieAttack_10.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
}
void ZombieFlag::initdie()
{
	dieanimFrames.reserve(8);
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/01.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/02.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/03.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/04.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/05.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/06.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/07.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/08.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/09.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
}

void ZombieFlag::update(float dt)
{
	if (hp <= 0) {
		state = 3;
	}
}