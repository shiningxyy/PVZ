#include"cherrybomb.h"

void Cherrybomb::update(float uptime) {
	if (get_blood() <= 0) {
		is_shoot(true);
		removeFromParent();
		this->unscheduleUpdate();
	}
}
void Cherrybomb::init_plant() {
	set_blood(CHERRY_BLOOD);
	set_type(CHERRYBOMB);
	is_plant(false);
	set_rate(CHERRY_RATE);
	is_shoot(false);
}
void Cherrybomb::init_animation() {
	auto mysprite = init_sprite(get_pos());
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(7);
	animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_0.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_1.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_2.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_3.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_4.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_5.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_6.png", Rect(0, 0, 80, 90)));

	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	mysprite->runAction(RepeatForever::create(animate));
}