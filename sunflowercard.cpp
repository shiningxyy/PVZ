#include"sunflowercard.h"

void Sunflowercard::update(float tim) {
	timecount += tim;
	if (is_cold()) {//´¦ÓÚÀäÈ´×´Ì¬£¬µ÷ÓÃÀäÈ´¶¯»­
		cold_animation();
		timecount = 0;
	}
	if (timecount > card_cd) {
		cold = false;
	}
}
void Sunflowercard::card_init() {
	card_cd = 10;//ÀäÈ´Ê±¼ä10s
	cost = 50;//50Ì«Ñô
	cold = false;//²»ÔÚÀäÈ´×´Ì¬
	ct = SUNFLOWER_CARD;
}
void Sunflowercard::cold_animation() {
	/*
	this->cd_sprite_init("CD", this->sprite->getPosition());
	this->cd_sprite->setColor(Color3B::GRAY);
	auto cd_cartoon = ProgressTimer::create(this->cd_sprite);
	cd_cartoon->setPosition(this->sprite->getPosition());
	cd_cartoon->setType(ProgressTimer::Type::BAR);
	cd_cartoon->setBarChangeRate(Vec2(0, 1));
	cd_cartoon->setMidpoint(Vec2(0, 1));
	cd_cartoon->runAction(ProgressFromTo::create(this->card_cd, 100, 0));
	this->sprite->getParent()->addChild(cd_cartoon, 3);
	*/
	auto cd1 = FadeOut::create(0.1);
	auto cd2 = FadeIn::create(card_cd);
	auto cd_seq = Sequence::create(cd1, cd2);
	this->sprite->runAction(cd_seq);
}