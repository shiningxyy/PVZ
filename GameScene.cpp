#include "GameScene.h"

int total_collection = 50;
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
	// set the background music and continuously play it.
	auto backgroundAudioID = AudioEngine::play2d("music/bg_daytime.mp3", true);


    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto gamebackground = Sprite::create("game/Background_0.jpg");
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
    toolbar->setPosition(Vec2(toolbar->getContentSize().width*0.9f / 2, visibleSize.height -toolbar->getContentSize().height * 0.9f / 2));
    this->addChild(toolbar, 1);

    createcar();
	auto listener = EventListenerTouchOneByOne::create();//创建鼠标监听
	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	createplant();

	/*
	{//生成初始阳光
		SUN* new_sun = new SUN(sunflower);
		new_sun->sunsprite->setScale(0.2f);
		this->addChild(new_sun->sunsprite, 3);
		suns.push_back(new_sun);
		new_sun->start_move();  // 生成阳光并下落
		//sun->jump(Vec2(400, 90));//给坐标，直接有阳光
		auto _mouseListener = EventListenerMouse::create();
		_mouseListener->onMouseDown = CC_CALLBACK_1(SUN::onMouseDown, new_sun);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
		//total_collection = suns.size() * 25;
		sun_num = Label::createWithTTF(std::to_string(0), "fonts/Marker Felt.ttf", 24);
		this->addChild(sun_num, 5);
		sun_num->setPosition(Vec2(40, Y_MAX - 80));  // 适当调整 Label 位置
		sun_num->enableShadow();
	}
	*/


    this->scheduleUpdate();
    return true;
}

void GameScene::createcar() {
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

void  GameScene::update(float updatetime)
{
	 this->producetime += updatetime;
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
		 if (is_lose == 1) {
			 
			 AudioEngine::stopAll();
			 auto backgroundAudioID = AudioEngine::play2d("music/lose.wav", false);
			 Director::getInstance()->replaceScene(LoseScene::create());
		 }
	 }

	 for (auto& it : cards) {
		 if (it->cold == true) {
			 it->time_count += updatetime;
			 if (it->card_cd <= it->time_count) {
				 it->cold = false;
				 it->time_count = 0;
			 }
		 }
	 }

	 if (producetime >= 10.0) {
		 producetime = 0;
		 SUN* new_sun = new SUN(sky);
		 new_sun->sunsprite->setScale(0.2f);
		 this->addChild(new_sun->sunsprite, 3);
		 suns.push_back(new_sun);

		 new_sun->start_move();  // 生成阳光并下落
		 //sun->jump(Vec2(400, 90));//给坐标，直接有阳光
		 auto _mouseListener = EventListenerMouse::create();
		 _mouseListener->onMouseDown = CC_CALLBACK_1(SUN::onMouseDown, new_sun);
		 _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
		 total_collection = 0;
		 for (SUN* sun : suns) {
			 total_collection += sun->collection;
		 }	

		 //total_collection = (suns.size()-1)*25;
		 auto cover = Sprite::create("game/cover.png");
		 
		 cover->setPosition(Vec2(40,Y_MAX-75));
		 this->addChild(cover, 4);
		 if (sun_num != nullptr) {
			 this->removeChild(sun_num);
		 }
		 sun_num = Label::createWithTTF(std::to_string(total_collection*25), "fonts/Marker Felt.ttf", 24);
		 this->addChild(sun_num, 5);
		 sun_num->setPosition(Vec2(40, Y_MAX - 80));  // 适当调整 Label 位置
		 sun_num->enableShadow();
	 }
	 else
	 {
		 total_collection = 0;
		 for (SUN* sun : suns) {
			 total_collection += sun->collection;
		 }
		 //total_collection = (suns.size()-1)*25;
		 auto cover = Sprite::create("game/cover.png");

		 cover->setPosition(Vec2(40, Y_MAX - 75));
		 this->addChild(cover, 4);
		 sun_num = Label::createWithTTF(std::to_string(total_collection * 25), "fonts/Marker Felt.ttf", 24);
		 this->addChild(sun_num, 5);
		 sun_num->setPosition(Vec2(40, Y_MAX - 80));  // 适当调整 Label 位置
		 sun_num->enableShadow();
	 }
	 //向日葵生成，豌豆生成
	 {
		 for (auto it = plants.begin(); it != plants.end(); it++) {
			 if ((*it)->get_blood() <= 0) {
				 (*it)->get_sprite()->removeFromParent();
				 (*it)->removeFromParent();
				 it = plants.erase(it);
				 continue;
			 }
			 if ((*it)->get_type() == SUNFLOWER) {
				 this->producetime3 += updatetime;
				 if (this->producetime3 >= (*it)->rate_time) {
					 this->producetime3 = 0.0;
					 for (auto ppos = sunflowerpos.begin(); ppos != sunflowerpos.end(); ppos++)
					 {
						 SUN* new_sun = new SUN(sunflower);
						 new_sun->sunsprite->setScale(0.2f);
						 this->addChild(new_sun->sunsprite, 3);
						 suns.push_back(new_sun);

						 //new_sun->start_move();  // 生成阳光并下落
						 new_sun->jump(*ppos);//给坐标，直接有阳光
						 auto _mouseListener = EventListenerMouse::create();
						 _mouseListener->onMouseDown = CC_CALLBACK_1(SUN::onMouseDown, new_sun);
						 _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
						 total_collection = 0;
						 for (SUN* sun : suns) {
							 total_collection += sun->collection;
						 }
						 //total_collection = (suns.size()-1)*25;
						 auto cover = Sprite::create("game/cover.png");
						 cover->setScale(1.1f);
						 cover->setPosition(Vec2(40, Y_MAX - 75));
						 this->addChild(cover, 4);
						 if (sun_num != nullptr) {
							 this->removeChild(sun_num);
						 }
						 sun_num = Label::createWithTTF(std::to_string(total_collection * 25), "fonts/Marker Felt.ttf", 24);
						 this->addChild(sun_num, 5);
						 sun_num->setPosition(Vec2(40, Y_MAX - 80));  // 适当调整 Label 位置
						 sun_num->enableShadow();
					 }
				 }
			 }			 
			 else if ((*it)->get_type() == PEASHOOTER) {
				 this->producetime2 += updatetime;
				 if (this->producetime2 >= (*it)->rate_time)
				 {
					 this->producetime2 = 0;			
					 for(auto ppos=peashooterpos.begin(); ppos != peashooterpos.end();ppos++)
					 {
						 Bullet b;
						 b.sprite_init(Vec2((*ppos).x, (*ppos).y + 10));
						 this->addChild(b.bulletsprite, 66);
						 b.bullet_move();
						 b.bullet_explode();
					 }
				 }
			 }
			 
		 }
		/*
		 for (auto it = plants.begin(); it != plants.end(); it++) {		 
			 if ((*it)->get_type() == PEASHOOTER) {
				 this->producetime2 += updatetime;
				 if (this->producetime2 >= 1.5)
				 {
					 this->producetime2 = 0;
					 Bullet b;
					 for(auto ppos=peashooterpos.begin(); ppos != peashooterpos.end();ppos++)
					 {
						 b.sprite_init(Vec2((*ppos).x, (*ppos).y + 10));
						 this->addChild(b.bulletsprite, 66);
						 b.bullet_move();
						 b.bullet_explode();
					 }
				 }
			 }
		 }
		*/
	 }
}

void GameScene::createzombie()
 {
	 int i = 10;
	 if (gametime ==10)
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
	 else if (gametime == 100) {
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
	 else if (gametime == 200) {
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

void GameScene::createplant() {
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
		 Cherrybombcard* c4 = new Cherrybombcard;
		 c4->sprite_init("cherrybomb", Vec2(285, 555));
		 this->addChild(c4->sprite, 2);
		 cards.push_back(c4);
	 }
 }

void GameScene::menuscene(Ref* pSender)
{
    Director::getInstance()->popScene();
}

void GameScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

bool GameScene::onTouchBegan(Touch* touch, Event* event)//触摸开始
{
	auto touchpos = touch->getLocation();

	for (int i = 0; i < 4; i++) {
		auto t = cards[i];
		if (t->cold == true || mouse_s != nullptr )//还在冷却，该卡不可选
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
				t->cold = true;
				Sunflower* sunf = new Sunflower;
				mouse_s = Sprite::create("SunFlower/SunFlower_0.png");
				mouse_s->setPosition(t->sprite->getPosition());
				//mouse_s = sunf->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::SUNFLOWER;
				t->cold_animation();
				break;
			}
			case PEASHOOTER_CARD:
			{
				t->cold = true;
				Peashooter* pea = new Peashooter;
				mouse_s = Sprite::create("Peashooter/Peashooter_0.png");
				mouse_s->setPosition(t->sprite->getPosition());
				//mouse_s = pea->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::PEASHOOTER;
				t->cold_animation();
				break;
			}
			case WALLNUT_CARD:
			{
				t->cold = true;
				Wallnut* wal = new Wallnut;
				mouse_s = Sprite::create("WallNut/WallNut_0.png");
				mouse_s->setPosition(t->sprite->getPosition());
				//mouse_s = wal->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::WALLNUT;
				t->cold_animation();
				break;
			}
			case CHERRYBOMB_CARD:
			{
				t->cold = true;
				Cherrybomb* che = new Cherrybomb;
				mouse_s = Sprite::create("CherryBomb/CherryBomb_0.png");
				mouse_s->setPosition(t->sprite->getPosition());
				//mouse_s = che->run_animation(t->sprite->getPosition());
				this->addChild(mouse_s, 1);
				ptype = PlantType::CHERRYBOMB;
				t->cold_animation();
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
	if (mouse_s != nullptr && ptype != NONE) {
		int row, col;
		Vec2 ppos = touch->getLocation();
		mouse_s->setPosition(touch->getLocation());
		compete_row_col(touch->getLocation(), row, col);
		{
			Plant* tempplant = NULL;
			switch (ptype) {
			case SUNFLOWER:
				tempplant = new Sunflower;
				tempplant->set_type(SUNFLOWER);
				{
					auto mySprite = Sprite::create("SunFlower/SunFlower_0.png");
					mySprite->setPosition(ppos);
					sunflowerpos.emplace_back(ppos);//把太阳花的坐标存起来
					this->addChild(mySprite, 0);
					Vector<SpriteFrame*> animFrames;
					animFrames.reserve(18);
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_0.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_1.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_2.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_3.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_4.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_5.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_6.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_7.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_8.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_9.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_10.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_11.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_12.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_13.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_14.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_15.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_16.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_17.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
					Animate* animate = Animate::create(animation);
					mySprite->runAction(RepeatForever::create(animate));

					/* {
						SUN* new_sun = new SUN(sunflower);
						new_sun->sunsprite->setScale(0.2f);
						this->addChild(new_sun->sunsprite, 3);
						suns.push_back(new_sun);
						//sun->start_move();  // 生成阳光并下落
						new_sun->jump(ppos);//给坐标，直接有阳光
						auto _mouseListener = EventListenerMouse::create();
						_mouseListener->onMouseDown = CC_CALLBACK_1(SUN::onMouseDown, new_sun);
						_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
						total_collection = 0;
						for (SUN* sun : suns) {
							total_collection += sun->collection;
						}
						//total_collection = total_collection/2;
						auto cover = Sprite::create("game/cover.png");
						cover->setScale(1.1f);
						cover->setPosition(Vec2(40, Y_MAX - 75));
						this->addChild(cover, 4);
						if (sun_num != nullptr) {
							this->removeChild(sun_num);
						}
						sun_num = Label::createWithTTF(std::to_string(total_collection*25), "fonts/Marker Felt.ttf", 24);
						
						this->addChild(sun_num, 5);
						sun_num->setPosition(Vec2(40, Y_MAX - 80));  // 适当调整 Label 位置
						sun_num->enableShadow();
					}*/
				}
				//this->addChild(tempplant->run_animation(plantpos));
				break;
			case PEASHOOTER:
				tempplant = new Peashooter;
				tempplant->set_type(PEASHOOTER);
				{
					Vector<SpriteFrame*> animFrames;
					auto mySprite = Sprite::create("Peashooter/Peashooter_0.png");
					mySprite->setPosition(ppos);
					peashooterpos.emplace_back(ppos);//把豌豆射手的坐标存起来
					this->addChild(mySprite, 0);
					animFrames.reserve(13);
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_0.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_1.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_2.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_3.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_4.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_5.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_6.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_7.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_8.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_9.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_10.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_11.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("Peashooter/Peashooter_12.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
					Animate* animate = Animate::create(animation);
					mySprite->runAction(RepeatForever::create(animate));
					{
						Bullet b;
						b.sprite_init(Vec2(ppos.x, ppos.y + 10));
						this->addChild(b.bulletsprite, 66);
						b.bullet_move();
						//b.bullet_explode();
					}
				}
				//this->addChild(tempplant->run_animation(plantpos));
				break;
			case WALLNUT:
				tempplant = new Wallnut;
				tempplant->set_type(WALLNUT);
				{
					Vector<SpriteFrame*> animFrames;
					auto mySprite = Sprite::create("WallNut/WallNut_0.png");
					mySprite->setPosition(ppos);
					this->addChild(mySprite, 0);
					animFrames.reserve(16);
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_0.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_1.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_2.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_3.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_4.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_5.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_6.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_7.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_8.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_9.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_10.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_11.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_12.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_13.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_14.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("WallNut/WallNut_15.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
					Animate* animate = Animate::create(animation);
					mySprite->runAction(RepeatForever::create(animate));
				}
				//this->addChild(tempplant->run_animation(plantpos));
				break;
			case CHERRYBOMB:
				tempplant = new Cherrybomb;
				tempplant->set_type(CHERRYBOMB);
				{
					Vector<SpriteFrame*> animFrames;
					auto mySprite = Sprite::create("CherryBomb/CherryBomb_0.png");
					mySprite->setPosition(ppos);
					mySprite->setScale(0.9f);
					this->addChild(mySprite, 0);
					animFrames.reserve(7);
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_0.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_1.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_2.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_3.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_4.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_5.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_6.png", Rect(0, 0, mySprite->getContentSize().width, mySprite->getContentSize().height)));
					Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
					Animate* animate = Animate::create(animation);
					mySprite->runAction(RepeatForever::create(animate));
				}
				//this->addChild(tempplant->run_animation(plantpos));
				break;
			default:
				break;
			}
			plants.emplace_back(tempplant);
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
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
		{
			//float x = 0.15f * i + 0.15f, y = 0.09f * j + 0.21f;

			//plant_pos[i][j] = Vec2(visibleSize.width * y, visibleSize.height * x);
			plant_pos[i][j] = Vec2(10 * i, 10 * j);
		}
}

void GameScene::plant(int row, int col, PlantType pt) {

	compete_plant_pos();
	Vec2 plantpos = plant_pos[row][col];
	Card* tempcard;
	int index = -1;
	switch (pt) {
	case SUNFLOWER:
		tempcard = cards[0];
		index = 0;
		break;
	case PEASHOOTER:
		tempcard = cards[1];
		index = 1;
		break;
	case WALLNUT:
		tempcard = cards[2];
		index = 2;
		break;
	case CHERRYBOMB:
		tempcard = cards[3];
		index = 3;
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
				{
					auto mySprite = Sprite::create("SunFlower/SunFlower_0.png");
					mySprite->setPosition(plantpos);
					this->addChild(mySprite, 0);
					Vector<SpriteFrame*> animFrames;
					animFrames.reserve(18);
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_0.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_1.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_2.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_3.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_4.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_5.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_6.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_7.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_8.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_9.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_10.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_11.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_12.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_13.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_14.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_15.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_16.png", Rect(0, 0, 64, 90)));
					animFrames.pushBack(SpriteFrame::create("SunFlower/SunFlower_17.png", Rect(0, 0, 64, 90)));
					Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
					Animate* animate = Animate::create(animation);
					mySprite->runAction(RepeatForever::create(animate));
				}
				//this->addChild(tempplant->run_animation(plantpos));
				break;
			case PEASHOOTER:
				tempplant = new Peashooter;
				tempplant->set_type(PEASHOOTER);
				{
					Vector<SpriteFrame*> animFrames;
					auto mySprite = Sprite::create("Peashooter/Peashooter_0.png");
					mySprite->setPosition(plantpos);
					this->addChild(mySprite, 0);
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
					mySprite->runAction(RepeatForever::create(animate));
				}
				//this->addChild(tempplant->run_animation(plantpos));
				break;
			case WALLNUT:
				tempplant = new Wallnut;
				tempplant->set_type(WALLNUT);
				{
					Vector<SpriteFrame*> animFrames;
					auto mySprite = Sprite::create("WallNut/WallNut_0.png");
					mySprite->setPosition(plantpos);
					this->addChild(mySprite, 0);
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
					mySprite->runAction(RepeatForever::create(animate));
				}
				//this->addChild(tempplant->run_animation(plantpos));
				break;
			case CHERRYBOMB:
				tempplant = new Cherrybomb;
				tempplant->set_type(CHERRYBOMB);
				{
					Vector<SpriteFrame*> animFrames;
					auto mySprite = Sprite::create("CherryBomb/CherryBomb_0.png");
					mySprite->setPosition(plantpos);
					mySprite->setScale(0.9f);
					this->addChild(mySprite, 0);
					animFrames.reserve(7);
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_0.png", Rect(0, 0, 110, 90)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_1.png", Rect(0, 0, 110, 90)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_2.png", Rect(0, 0, 110, 90)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_3.png", Rect(0, 0, 110, 90)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_4.png", Rect(0, 0, 110, 90)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_5.png", Rect(0, 0, 110, 90)));
					animFrames.pushBack(SpriteFrame::create("CherryBomb/CherryBomb_6.png", Rect(0, 0, 110, 90)));
					Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
					Animate* animate = Animate::create(animation);
					mySprite->runAction(RepeatForever::create(animate));
				}
				//this->addChild(tempplant->run_animation(plantpos));
				break;
			default:
				break;
			}
			plants.push_back(tempplant);
		}
	}
}