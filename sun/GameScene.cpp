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

    sun = new SUN(sunflower);
    this->addChild(sun->sunsprite, 3);
    //sun->start_move();  // 生成阳光并下落
    sun->jump(Vec2(400, 90));//给坐标，直接有阳光
    auto _mouseListener = EventListenerMouse::create();
   _mouseListener->onMouseDown = CC_CALLBACK_1(SUN::onMouseDown, sun);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);
    
    /*Bullet b;
    b.sprite_init(Vec2(500, 90));
    this->addChild(b.bulletsprite, 66);
    //b.bullet_move();
    b.bullet_explode();*/

    sun_num = Label::createWithTTF(std::to_string((sun->collection)*25), "fonts/Marker Felt.ttf", 24);
    this->addChild(sun_num, 5);
    sun_num->setPosition(Vec2(40,Y_MAX-80));  // 适当调整 Label 位置
    sun_num->enableShadow();
    return true;
}


void GameScene::menuscene(Ref* pSender)
{
    Director::getInstance()->popScene();
}
