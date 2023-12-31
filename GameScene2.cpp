#include "GameScene2.h"


Scene* GameScene2::createScene()
{
	return GameScene2::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene2::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto gamebackground = Sprite::create("background3.jpg");
	gamebackground->setScale(1.0f);
	gamebackground->setPosition(Vec2(gamebackground->getContentSize().width / 2, visibleSize.height / 2 + origin.y));
	this->addChild(gamebackground, -1);
	/* gamebackground->setPosition(Vec2(visibleSize.width - gamebackground->getContentSize().width / 2, visibleSize.height / 2 + origin.y));
	 this->addChild(gamebackground, -1);
	 gamebackground->runAction(MoveTo::create(1.0f, Vec2(gamebackground->getContentSize().width / 2, visibleSize.height / 2 + origin.y)));
	 */

	 /*auto PanelBackground = Sprite::create("game/PanelBackground.png");
	 PanelBackground->setScale(1.0f);
	 PanelBackground->setPosition(Vec2(PanelBackground->getContentSize().width / 2, visibleSize.height / 2 + origin.y));
	 DelayTime::create(1.0f);
	 this->addChild(PanelBackground, 0);
	 */
	auto toolbar = Sprite::create("game/toolbarWithoutShovel.png");
	toolbar->setScale(0.9f);
	toolbar->setPosition(Vec2(toolbar->getContentSize().width * 0.9f / 2, visibleSize.height - toolbar->getContentSize().height * 0.9f / 2));
	this->addChild(toolbar, 1);

	createcar();



	this->scheduleUpdate();
	return true;
}

void GameScene2::createcar() {
	auto car1 = Car::create();
	car1->car->setPosition(Vec2(220, 460));
	car1->setrow(5);
	this->addChild(car1, 2);
	carnumber.pushBack(car1);

	auto car2 = Car::create();
	car2->car->setPosition(Vec2(216, 360));
	car2->setrow(4);
	this->addChild(car2, 3);
	carnumber.pushBack(car2);

	auto car3 = Car::create();
	car3->car->setPosition(Vec2(212, 260));
	car3->setrow(3);
	this->addChild(car3, 4);
	carnumber.pushBack(car3);

	auto car4 = Car::create();
	car4->car->setPosition(Vec2(208, 160));
	car4->setrow(2);
	this->addChild(car4, 5);
	carnumber.pushBack(car4);

	auto car5 = Car::create();
	car5->car->setPosition(Vec2(204, 60));
	car5->setrow(1);
	this->addChild(car5, 6);
	carnumber.pushBack(car5);
}

void  GameScene2::update(float)
{


	gametime++;
	createzombie();
	for (auto& it : zombienumber)
	{
		if (it->state == 3)
			continue;
		else {
			for (auto& it2 : carnumber) {
				if (it->row == it2->row) {
					log("%f", it2->getx());

					if (fabs(it->getx() - it2->getx()) <= 5) {
						if (it2->state != 1) {
							it2->setstate(1);
							it2->runaction();
							if (it->state != 3) {
								it->setstate(3);
								it->runaction();
							}
						}
					}
				}
			}
		}
	}
	if (gametime > 11) {
		int is_win = 1, is_lose = 0;
		for (auto& it : zombienumber)
		{
			if (it->state != 3) {
				is_win = 0;
				if (it->getx() < 150)
					is_lose = 1;
			}
		}
		if (is_win == 1)
			Director::getInstance()->replaceScene(WinScene::create());
		if (is_lose == 1)
			Director::getInstance()->replaceScene(LoseScene::create());
	}

}


void GameScene2::createzombie()
{
	int i = 10;
	if (gametime == 10)
	{
		auto ZOMBIE11 = ZombieNormal::create();
		ZOMBIE11->zombie->setPosition(Vec2(1200, 500));
		ZOMBIE11->setrow(5);
		ZOMBIE11->setmovelength(1200);
		this->addChild(ZOMBIE11, i++);
		ZOMBIE11->runaction();
		zombienumber.pushBack(ZOMBIE11);
		auto ZOMBIE13 = ZombieNormal::create();
		ZOMBIE13->zombie->setPosition(Vec2(1300, 200));
		ZOMBIE13->setrow(2);
		ZOMBIE13->setmovelength(1500);
		this->addChild(ZOMBIE13, i++);
		ZOMBIE13->runaction();
		zombienumber.pushBack(ZOMBIE13);

	}
	else if (gametime == 500) {
		auto ZOMBIE21 = ZombieNormal::create();
		ZOMBIE21->zombie->setPosition(Vec2(1500, 400));
		ZOMBIE21->setrow(4);
		ZOMBIE21->setmovelength(1500);
		this->addChild(ZOMBIE21, i++);
		ZOMBIE21->runaction();
		zombienumber.pushBack(ZOMBIE21);
		auto ZOMBIE22 = ZombieBucket::create();
		ZOMBIE22->zombie->setPosition(Vec2(1600, 300));
		ZOMBIE22->setrow(3);
		ZOMBIE22->setmovelength(2000);
		this->addChild(ZOMBIE22, i++);
		ZOMBIE22->runaction();
		zombienumber.pushBack(ZOMBIE22);
		auto ZOMBIE23 = ZombieNormal::create();
		ZOMBIE23->zombie->setPosition(Vec2(2000, 200));
		ZOMBIE23->setrow(2);
		ZOMBIE23->setmovelength(2200);
		this->addChild(ZOMBIE23, i++);
		ZOMBIE23->runaction();
		zombienumber.pushBack(ZOMBIE23);
	}
	else if (gametime == 1000) {
		auto ZOMBIE31 = ZombieFlag::create();
		ZOMBIE31->zombie->setPosition(Vec2(1500, 300));
		ZOMBIE31->setrow(3);
		ZOMBIE31->setmovelength(1500);
		this->addChild(ZOMBIE31, i++);
		ZOMBIE31->runaction();
		zombienumber.pushBack(ZOMBIE31);

		auto ZOMBIE32 = ZombieNormal::create();
		ZOMBIE32->zombie->setPosition(Vec2(1800, 500));
		ZOMBIE32->setrow(5);
		ZOMBIE32->setmovelength(1800);
		this->addChild(ZOMBIE32, i++);
		ZOMBIE32->runaction();
		zombienumber.pushBack(ZOMBIE32);

		auto ZOMBIE33 = ZombieBucket::create();
		ZOMBIE33->zombie->setPosition(Vec2(2100, 200));
		ZOMBIE33->setrow(2);
		ZOMBIE33->setmovelength(2000);
		this->addChild(ZOMBIE33, i++);
		ZOMBIE33->runaction();
		zombienumber.pushBack(ZOMBIE33);

		auto ZOMBIE34 = ZombieNormal::create();
		ZOMBIE34->zombie->setPosition(Vec2(1800, 200));
		ZOMBIE34->setrow(2);
		ZOMBIE34->setmovelength(1800);
		this->addChild(ZOMBIE34, i++);
		ZOMBIE34->runaction();
		zombienumber.pushBack(ZOMBIE34);

		auto ZOMBIE35 = ZombieBucket::create();
		ZOMBIE35->zombie->setPosition(Vec2(1900, 100));
		ZOMBIE35->setrow(1);
		ZOMBIE35->setmovelength(1900);
		this->addChild(ZOMBIE35, i++);
		ZOMBIE35->runaction();
		zombienumber.pushBack(ZOMBIE35);
	}

}

