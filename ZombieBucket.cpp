
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
	return true;

}
void ZombieBucket::initmove()
{
	moveanimFrames.reserve(15);
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_0.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_1.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_2.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_3.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_4.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_5.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_6.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_7.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_8.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_9.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_10.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_11.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_12.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_13.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	moveanimFrames.pushBack(SpriteFrame::create("BucketZombie/Move/Zombie_14.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
}
void ZombieBucket::initattack()
{
	attackanimFrames.reserve(11);
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_0.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_1.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_2.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_3.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_4.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_5.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_6.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_7.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_8.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_9.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
	attackanimFrames.pushBack(SpriteFrame::create("BucketZombie/Attack/ZombieAttack_10.png", Rect(0, 0, zombie->getContentSize().width, zombie->getContentSize().height)));
}
void ZombieBucket::initdie()
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
