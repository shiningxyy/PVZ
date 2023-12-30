#include "GameScene.h"
Scene* GameScene::createScene()
{
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto gamebackground = Sprite::create("game/Background_0.jpg");
    gamebackground->setScale(1.0f);
    gamebackground->setPosition(Vec2(gamebackground->getContentSize().width /2, visibleSize.height / 2 + origin.y));
    this->addChild(gamebackground, 0);
    /*gamebackground->runAction(MoveTo::create(1.0f, Vec2(visibleSize.width - gamebackground->getContentSize().width / 2, visibleSize.height / 2 + origin.y)));
    auto PanelBackground = Sprite::create("game/PanelBackground.png");
    PanelBackground->setScale(1.0f);
    PanelBackground->setPosition(Vec2(PanelBackground->getContentSize().width / 2, visibleSize.height / 2 + origin.y));
    DelayTime::create(1.0f);
    this->addChild(PanelBackground, 1);
    */
    auto toolbar = Sprite::create("game/toolbarWithoutShovel.png");
    toolbar->setScale(0.9f);
    toolbar->setPosition(Vec2(toolbar->getContentSize().width*0.9f / 2, visibleSize.height -toolbar->getContentSize().height * 0.9f / 2));
    this->addChild(toolbar, 1);

	auto listener = EventListenerTouchOneByOne::create();//创建鼠标监听
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);

	{//创建植物卡片
		Sunflowercard* c1 = new Sunflowercard;
		c1->sprite_init("sunflower", Vec2(105, 555));
		this->addChild(c1->sprite, 2);
		cards.push_back(c1);
		Peashootercard* c2 = new Peashootercard;
		c2->sprite_init("peashooter", Vec2(165, 555));
		this->addChild(c2->sprite, 2);
		cards.push_back(c2);
		Wallnutcard* c3 = new Wallnutcard;
		c3->sprite_init("wallnut", Vec2(225, 555));
		this->addChild(c3->sprite, 2);
		cards.push_back(c3);
		Squashcard* c4 = new Squashcard;
		c4->sprite_init("squash", Vec2(285, 555));
		this->addChild(c4->sprite, 2);
		cards.push_back(c4);
		Cherrybombcard* c5 = new Cherrybombcard;
		c5->sprite_init("cherrybomb", Vec2(345, 555));
		this->addChild(c5->sprite, 2);
		cards.push_back(c5);
	}

    return true;
}

void GameScene::menuCloseCallback(Ref* pSender)
{	
	Director::getInstance()->end();
}

void GameScene::menuscene(Ref* pSender)
{
    Director::getInstance()->popScene();
}

bool GameScene::onTouchBegan(Touch* touch, Event* event)//触摸开始
{
	auto touchpos = touch->getLocation();

	for (auto& t : cards) {
		if (t->is_cold() || mouse_s != nullptr)//还在冷却，该卡不可选
			continue;
		double w = t->sprite->getContentSize().width / 2;
		double h = t->sprite->getContentSize().height / 2;
		Vec2 cardpos = t->sprite->getPosition();
		auto len = cardpos - touchpos;

		if ((fabs(len.x) <= w) && (fabs(len.y) <= h))//鼠标在卡片上
		{
			switch (t->ct)
			{
			
			case SUNFLOWER_CARD:
			{
				Sunflower* sunf = new Sunflower;
				mouse_s = sunf->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::SUNFLOWER;
				break;
			}
			case PEASHOOTER_CARD:
			{
				Peashooter* pea = new Peashooter;
				mouse_s = pea->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::PEASHOOTER;
				break;
			}
			case WALLNUT_CARD:
			{
				Wallnut* wal = new Wallnut;
				mouse_s = wal->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::WALLNUT;
				break;
			}
			case SQUASH_CARD:
			{
				Squash* squ = new Squash;
				mouse_s = squ->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::SQUASH;
				break;
			}
			case CHERRYBOMB_CARD:
			{
				Peashooter* che = new Peashooter;
				mouse_s = che->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::CHERRYBOMB;
				break;
			}
			default:
				break;
			}
			return true;
		}
	}
	return false;
}

void GameScene::onTouchMoved(Touch* touch, Event* event) {
	if (mouse_s != nullptr && ptype != NONE) {
		int row, col;
		mouse_s->setPosition(touch->getLocation());
		if (compete_row_col(touch->getLocation(), row, col)) {//鼠标在草坪上
			//该位置无植物
			mouse_s->setPosition(plant_pos[row][col]);

		}
		else
			mouse_s->setPosition(touch->getLocation());
	}
	
}

void GameScene::onTouchEnded(Touch* touch, Event* event)//触摸结束
{
	//鼠标位置在格子上!
	
	if (mouse_s != nullptr && ptype != NONE) {
		int row, col;
		mouse_s->setPosition(touch->getLocation());
		if (compete_row_col(touch->getLocation(), row, col)) {
			//该位置无植物!
			plant(row, col, ptype);
		}
		ptype = NONE;
	}
	
	this->removeChild(mouse_s, 1);
	mouse_s = nullptr;

}

bool GameScene::compete_row_col(Vec2 vpos, int& row, int& col) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if ((vpos.x < visibleSize.width * 0.18) || (vpos.x > visibleSize.width * 0.95) ||
		(vpos.y < visibleSize.height * 0.13) || (vpos.y > visibleSize.height * 0.92))
		return false;
		int w = 125 / 2, h = 103 / 2;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++) {
			Vec2 offset = vpos - plant_pos[i][j];
			if ((fabs(offset.x) <= w) && fabs(offset.y) <= h) {
				row = i, col = j;
				return true;
			}
		}
	return false;
}

void GameScene::compete_plant_pos() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	for(int i=0;i<5;i++)
		for (int j = 0; j < 9; j++)
		{
			float x = 0.15f * i + 0.15f, y = 0.09f * j + 0.21f;
			plant_pos[i][j] = Vec2(visibleSize.width * y, visibleSize.height * x);
		}
}

void GameScene::plant(int row, int col, PlantType pt) {

	compete_plant_pos();
	Vec2 plantpos=plant_pos[row][col];
	Card* tempcard ;
	int index = -1;
	switch (pt) {
	case SUNFLOWER:
		tempcard = cards[0];
		index = 0;
		break;
	case PEASHOOTER:
		tempcard = cards[1];
		index == 1;
		break;
	case WALLNUT:
		tempcard = cards[2];
		index = 2;
		break;
	case SQUASH:
		tempcard = cards[3];
		index = 3;
		break;
	case CHERRYBOMB:
		tempcard = cards[4];
		index = 4;
		break;
	default:
		break;
	}
	if (tempcard->cold == 0) {//不在冷却时间
		//if 阳光总量>=temp->cost
		{
			//阳光总量-=tempcard->cost;
			cards[index]->set_cold(true);
			cards[index]->cold_animation();
			Plant* tempplant = NULL;
			switch (pt) {
			case SUNFLOWER:
				tempplant = new Sunflower;
				tempplant->set_type(SUNFLOWER);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			case PEASHOOTER:
				tempplant = new Peashooter;
				tempplant->set_type(PEASHOOTER);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			case WALLNUT:
				tempplant = new Wallnut;
				tempplant->set_type(WALLNUT);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			case SQUASH:
				tempplant = new Squash;
				tempplant->set_type(SQUASH);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			case CHERRYBOMB:
				tempplant = new Cherrybomb;
				tempplant->set_type(CHERRYBOMB);
				this->addChild(tempplant->run_animation(plantpos));
				break;
			default:
				break;
			}
			plants.push_back(tempplant);
		}
	}
}