#include "StartScene.h"

Scene* StartScene::createScene()
{
    return StartScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto Menubackground = Sprite::create("start.png");
    Menubackground->setScale(0.6f);
    Menubackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y-10));
    this->addChild(Menubackground, 0);

    auto startbutton = MenuItemImage::create(
        "startbutton.png",
        "startbutton.png",
        CC_CALLBACK_1(StartScene::manuscene, this));
    startbutton->setScale(0.6f);
    startbutton->setPosition(Vec2(visibleSize.width / 2+90 + origin.x, 40));

    auto menu = Menu::create(startbutton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}


void StartScene::manuscene(Ref* pSender)
{
    Director::getInstance()->replaceScene(MenuScene::createScene());
}


