#include"wallnut.h"


void Wallnut::update(float uptime) {
	if (get_blood() <= 0)
	{
		removeFromParent();
		this->unscheduleUpdate();
	}
}
void Wallnut::init_plant() {
	set_blood(WALLNUT_BLOOD);
	set_type(WALLNUT);
	is_plant(false);
	set_rate(WALLNUT_RATE);

}
void Wallnut::init_animation() {
	auto mysprite = init_sprite(get_pos());
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(16);
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_0.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_1.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_2.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_3.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_4.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_5.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_6.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_7.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_8.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_9.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_10.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_11.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_12.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_13.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_14.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_15.png", Rect(0, 0, 80, 90)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	mysprite->runAction(RepeatForever::create(animate));
}