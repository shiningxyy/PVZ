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
#include"AudioEngine.h"
#include "ui/CocosGUI.h"
#include<vector>
USING_NS_CC;

/*//创建卡片的写法
应该放到游戏场景里实现*/
void createcard() {
	Sunflowercard* c1 = new Sunflowercard;
	c1->sprite_init("sunflower", Vec2(135, 555));
	this->addChild(c1->sprite, 2);

	Peashootercard* c2 = new Peashootercard;
	c2->sprite_init("peashooter", Vec2(195, 555));
	this->addChild(c2->sprite, 2);

	Wallnutcard* c3 = new Wallnutcard;
	c3->sprite_init("wallnut", Vec2(255, 555));
	this->addChild(c3->sprite, 2);

	Squashcard* c4 = new Squashcard;
	c4->sprite_init("squash", Vec2(315, 555));
	this->addChild(c4->sprite, 2);

	Cherrybombcard* c5 = new Cherrybombcard;
	c5->sprite_init("cherrybomb", Vec2(375, 555));
	this->addChild(c5->sprite, 2);
}



/*暂停场景*/

class PauseScene :public Scene {
public:
	Scene* createscene() { return PauseScene::create(); };
	virtual bool init();
	void menuCloseCallback(Ref* pSender);
};
bool PauseScene::init() {
	if (!PauseScene::init())
		return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto pause_bg1 = Sprite::create("");
	pause_bg1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(pause_bg1, 0);

	auto pause_bg2 = Sprite::create("");
	pause_bg2->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	pause_bg2->setScale(1.5f);
	this->addChild(pause_bg2, 1);

	auto certainbutton = Button::create("");//确认键
	//certainbutton->setTitleText("Button Text");
	certainbutton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			//std::cout << "Button 1 clicked" << std::endl;
			break;
		default:
			break;
		}
		});
	certainbutton->setPosition(Vec2(visibleSize.width / 2 +0.2, visibleSize.height / 2 +0.4));
	pause_bg2->addChild(certainbutton);

	auto continuebutton = Button::create("");//继续键
	//continuebutton ->setTitleText("Button Text");
	continuebutton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			//std::cout << "Button 1 clicked" << std::endl;
			break;
		default:
			break;
		}
		});
	continuebutton->setScale(0.4f);
	continuebutton->setPosition(Vec2(visibleSize.width / 2 + 0.2, visibleSize.height / 2 + 0.8));
	pause_bg2->addChild(continuebutton);

	auto backnormal= Label::createWithSystemFont("退出游戏", "Arial", 20);
	auto backselected= Label::createWithSystemFont("退出游戏", "Arial", 22);
	auto backItem = MenuItemSprite::create(backnormal, backselected, CC_CALLBACK_1(PauseScene::menuCloseCallback,this));
	backItem->setPosition(Vec2::ZERO);
	auto menu1 = Menu::create(backItem, nullptr);
	menu1->setPosition(Vec2(visibleSize.width / 2 + 0.5, visibleSize.height / 2 + 0.38));
	this->addChild(menu1, 1);
	return true;
}
void PauseScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}