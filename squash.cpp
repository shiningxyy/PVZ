#include"squash.h"



void Squash::delete_() {
	if (get_blood() <= 0) {
		removeFromParent();
		this->unscheduleUpdate();
	}
	{//Óöµ½½©Ê¬¹¥»÷

	}
}
void Squash::init_plant() {
	set_blood(SQUASH_BLOOD);
	set_type(SQUASH);
	is_plant(false);
	set_rate(SQUASH_RATE);

}
void Squash::init_animation() {
	Vector<SpriteFrame*> animFrames;
	auto mysprite = init_sprite(get_pos());
	animFrames.reserve(17);
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_0.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_1.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_2.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_3.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_4.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_5.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_6.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_7.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_8.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_9.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_10.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_11.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_12.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_13.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_14.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_15.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Squash/Squash/Squash_16.png", Rect(0, 0, 80, 90)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	mysprite->runAction(RepeatForever::create(animate));
}
void Squash::attack_animation() {
	auto mysprite = init_sprite(get_pos());
	auto aim = SpriteFrame::create("Squash/SquashAim/SquashAim_0.png", Rect(0, 0, 80, 90));
	auto attack0 = SpriteFrame::create("Squash/SquashAttack/SquashAttack_0.png", Rect(0, 0, 80, 90));
	auto attack1 = SpriteFrame::create("Squash/SquashAttack/SquashAttack_1.png", Rect(0, 0, 80, 90));
	auto attack2 = SpriteFrame::create("Squash/SquashAttack/SquashAttack_2.png", Rect(0, 0, 80, 90));
	auto attack3 = SpriteFrame::create("Squash/SquashAttack/SquashAttack_3.png", Rect(0, 0, 80, 90));
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(5);
	animFrames.pushBack(aim);
	animFrames.pushBack(attack0);
	animFrames.pushBack(attack1);
	animFrames.pushBack(attack2);
	animFrames.pushBack(attack3);
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.2f);
	Animate* animate = Animate::create(animation);
	mysprite->runAction(animate);
}