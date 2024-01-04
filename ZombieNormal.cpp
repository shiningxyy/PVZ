
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
	moverate = 20;
	zombie = Sprite::create("NormalZombie/Move/Zombie_0.png");
	this->addChild(zombie);
	initmove();
	initattack();
	initdie();
	return true;

}

void ZombieNormal::initmove()
{
	moveanimFrames.reserve(22);
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_0.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_1.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_2.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_3.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_4.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_5.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_6.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_7.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_8.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_9.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_10.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_11.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_12.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_13.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_14.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_15.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_16.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_17.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_18.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_19.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_20.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("NormalZombie/Move/Zombie_21.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
}
void ZombieNormal::initattack()
{
	attackanimFrames.reserve(21);
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_0.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_1.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_2.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_3.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_4.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_5.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_6.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_7.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_8.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_9.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_10.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_11.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_12.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_13.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_14.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_15.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_16.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_17.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_18.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_19.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("NormalZombie/Attack/ZombieAttack_20.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
}
void ZombieNormal::initdie()
{
	dieanimFrames.reserve(8);
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/01.png", Rect(0, 0, zombie->getContentSize().width+50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/02.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/03.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/04.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/05.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/06.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/07.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/08.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
	dieanimFrames.pushBack(SpriteFrame::create("NormalZombie/Die/09.png", Rect(0, 0, zombie->getContentSize().width + 50, zombie->getContentSize().height)));
}
