#include "GameScene.h"

Vector<ZombieBase*> zombienumber;//用于保存已经创建的僵尸
Vector<Car*> carnumber;
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

    auto car1 = Car::create();
    car1->car->setPosition(Vec2(220, 460));
    car1->setrow(1);
    this->addChild(car1, 2);
    carnumber.pushBack(car1);
    
    auto car2 = Car::create();
    car2->setPosition(Vec2(216, 360));
    car1->setrow(2);
    this->addChild(car2, 3);
    carnumber.pushBack(car2);

    auto car3 = Car::create();
    car3->setPosition(Vec2(212, 260));
    car1->setrow(3);
    this->addChild(car3, 4);
    carnumber.pushBack(car3);

    auto car4 = Car::create();
    car4->setPosition(Vec2(208, 160));
    car1->setrow(4);
    this->addChild(car4, 5);
    carnumber.pushBack(car4);

    auto car5 = Car::create();
    car5->setPosition(Vec2(204, 60));
    car1->setrow(5);
    this->addChild(car5, 6);
    carnumber.pushBack(car5);
    auto ZOMBIE = ZombieNormal::create();
    ZOMBIE->zombie->setPosition(Vec2(1200, 500));
    ZOMBIE->setrow(1);
    this->addChild(ZOMBIE, 7);        
    ZOMBIE->runaction();
    zombienumber.pushBack(ZOMBIE);


    this->scheduleUpdate();
    return true;
}
 void  GameScene::update(float)
{
     if (zombienumber.front()->state!=3) {
         if (fabs(zombienumber.front()->getx() - carnumber.front()->getx()) <= 5) {
             if (carnumber.front()->state != 1) {
                 carnumber.front()->setstate(1);
                 carnumber.front()->runaction();
             }
             if (zombienumber.front()->state != 3) {
                 zombienumber.front()->setstate(3);
                 zombienumber.front()->runaction();
             }
         }
     }

}

void GameScene::menuscene(Ref* pSender)
{
    Director::getInstance()->popScene();
}
