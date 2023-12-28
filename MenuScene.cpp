#include "MenuScene.h"

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto Menubackground = Sprite::create("Menu/Menu.png");
    Menubackground->setScale(1.14f);
    Menubackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(Menubackground, 0);

    auto startbutton = MenuItemImage::create(
        "Menu/button.png",
        "Menu/button.png",
        CC_CALLBACK_1(MenuScene::gamescene, this));
    auto musicbutton = MenuItemImage::create(
        "Menu/button.png",
        "Menu/button.png",
        CC_CALLBACK_1(MenuScene::musicscene, this));
    startbutton->setScale(1.1f);
    startbutton->setPosition(Vec2(710, 460));
    musicbutton->setScale(1.0f);
    musicbutton->setPosition(Vec2(700, 300));
    musicbutton->setRotation(2.0f);
    auto menu = Menu::create(startbutton, NULL);
    menu->setPosition(Vec2::ZERO);
    menu->addChild(musicbutton);
    this->addChild(menu, 1);

    return true;
}


void MenuScene::musicscene(Ref* pSender)
{
    Director::getInstance()->pushScene(MusicScene::createScene());
}

void MenuScene::gamescene(Ref* pSender)
{
    Director::getInstance()->end();
}
