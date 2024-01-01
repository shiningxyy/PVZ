#include"sunflower.h"


void Sunflower::init_plant() {

	set_blood(SUNFLOWER_BLOOD);
	set_type(SUNFLOWER);
	is_plant(false);
	set_rate(SUNFLOWER_RATE);
}

void Sunflower::update(float uptime) {
	if (get_blood() <= 0)
	{
		removeFromParent();
		this->unscheduleUpdate();
	}
}
void Sunflower::init_animation() {
    auto mysprite = init_sprite(get_pos());
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(18);
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_0.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_1.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_2.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_3.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_4.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_5.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_6.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_7.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_8.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_9.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_10.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_11.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_12.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_13.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_14.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_15.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_16.png", Rect(0, 0, 80, 90)));
    animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_17.png", Rect(0, 0, 80, 90)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	mysprite->runAction(RepeatForever::create(animate));
}