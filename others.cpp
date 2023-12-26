#include"plant.h"
#include"sunflower.h"
#include"peashooter.h"
#include"squash.h"
#include"wallnut.h"
#include"cherrybomb.h"
#include"card.h"
#include"sunflowercard.h"
#include"peashootercard.h"
#include"squashcard.h"
#include"wallnutcard.h"
#include"cherrybombcard.h"

void init() {
	Sunflowercard* c1 = new Sunflowercard;
	c1->sprite_init("SunFlower", Vec2(135, 555));
	c1->addChild(c1->sprite, 2);

	Peashootercard* c2 = new Peashootercard;
	c2->sprite_init("Peashooter", Vec2(185, 555));
	c2->addChild(c2->sprite, 2);

	Squashcard* c3 = new Squashcard;
	c3->sprite_init("Squash", Vec2(235, 555));
	c3->addChild(c1->sprite, 2);

	Wallnutcard* c4 = new Wallnutcard;
	c4->sprite_init("Wallnut", Vec2(285, 555));
	c4->addChild(c4->sprite, 2);

	Cherrybombcard* c5 = new Cherrybombcard;
	c5->sprite_init("Cherrybomb", Vec2(335, 555));
	c5->addChild(c5->sprite, 2);
}