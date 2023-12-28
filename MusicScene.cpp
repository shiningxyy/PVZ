#include "MusicScene.h"

Scene* MusicScene::createScene()
{
    return MusicScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MusicScene::init()
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
    auto MusicBackground = Sprite::create("Menu/LevelManager.png");
    MusicBackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(MusicBackground, 1);

    auto closebutton = MenuItemImage::create(
        "Menu/close.png",
        "Menu/close.png",
        CC_CALLBACK_1(MusicScene::menuscene, this));
    closebutton->setScale(1.1f);
    closebutton->setPosition(Vec2(860, 500));
    auto menu = Menu::create(closebutton, NULL);
   
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}


void MusicScene::menuscene(Ref* pSender)
{
    Director::getInstance()->popScene();
}
