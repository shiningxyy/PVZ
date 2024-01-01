#include"squashcard.h"

void Squashcard::update(float tim) {
	timecount += tim;
	if (is_cold()) {//´¦ÓÚÀäÈ´×´Ì¬£¬µ÷ÓÃÀäÈ´¶¯»­
		cold_animation();
		timecount = 0;
	}
	if (timecount > card_cd) {
		cold = false;
	}
}
void Squashcard::card_init() {
	card_cd = 20;//ÀäÈ´Ê±¼ä20s
	cost = 50;//50Ì«Ñô
	cold = false;//²»ÔÚÀäÈ´×´Ì¬
	ct = SQUASH_CARD;
}
void Squashcard::cold_animation() {
	auto cd1 = FadeOut::create(0.1);
	auto cd2 = FadeIn::create(card_cd);
	auto cd_seq = Sequence::create(cd1, cd2);
	this->sprite->runAction(cd_seq);
}