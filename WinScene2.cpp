#include "WinScene2.h"

Scene* WinScene2::createScene()
{
    return WinScene2::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool WinScene2::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto Menubackground = Sprite::create("game/Background_0.jpg");
    Menubackground->setScale(1.14f);
    Menubackground->setPosition(Vec2(Menubackground->getContentSize().width / 2 + origin.x, Menubackground->getContentSize().height / 2 + origin.y));
    this->addChild(Menubackground, 0);
    auto MusicBackground = Sprite::create("Menu/LevelManager.png");
    MusicBackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(MusicBackground, 1);

    auto closebutton = MenuItemImage::create(
        "Menu/close.png",
        "Menu/close.png",
        CC_CALLBACK_1(WinScene2::menuscene, this));
    closebutton->setScale(1.1f);
    closebutton->setPosition(Vec2(860, 500));

    auto victory = Label::createWithTTF("Victory!", "fonts/Marker Felt.ttf", 100);
    victory->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    victory->setColor(Color3B(0, 0, 0));
    this->addChild(victory, 5);
    auto menu = Menu::create(closebutton, NULL);

    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    return true;
}


void WinScene2::menuscene(Ref* pSender)
{
    Director::getInstance()->replaceScene(MenuScene::createScene());
}


