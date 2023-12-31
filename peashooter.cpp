#include"peashooter.h"



void Peashooter::update(float uptime) {
	if (get_blood() <= 0) {
		removeFromParent();
		this->unscheduleUpdate();
	}
	else {
		this->set_interval(uptime);
		if (this->get_interval() > this->get_rate()) {
			this->set_interval(-this->get_interval());
			this->is_shoot(true);
		}
	}
}
void Peashooter::init_plant() {
	set_blood(PEASHOOTER_BLOOD);
	set_type(PEASHOOTER);
	is_plant(false);
	set_rate(PEASHOOTER_RATE);
	is_shoot(false);
}
void Peashooter::init_animation() {
	/*
	cocos2d::Vector<cocos2d::SpriteFrame*>sf;
	load_animation("Plants/Peashooter/Peashooter_default.plist", 13, sf);//这里的数字需要根据素材确定 
	set_firstframe(sf.front());
	auto animation = Animation::createWithSpriteFrames(sf, 1.0f / 8);
	set_animation(Animate::create(animation));
	return;
	*/
	Vector<SpriteFrame*> animFrames;
	auto mysprite = init_sprite(get_pos());
	animFrames.reserve(13);
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_0.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_1.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_2.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_3.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_4.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_5.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_6.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_7.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_8.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_9.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_10.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_11.png", Rect(0, 0, 80, 90)));
	animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_12.png", Rect(0, 0, 80, 90)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	mysprite->runAction(RepeatForever::create(animate));
}