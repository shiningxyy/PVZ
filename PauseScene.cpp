#include"PauseScene.h"


bool PauseScene::init() {
	if (!PauseScene::init())
		return false;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto pause_bg1 = Sprite::create("dialog.png");
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
	certainbutton->setPosition(Vec2(visibleSize.width / 2 + 0.2, visibleSize.height / 2 + 0.4));
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

	auto backnormal = Label::createWithSystemFont("退出游戏", "Arial", 20);
	auto backselected = Label::createWithSystemFont("退出游戏", "Arial", 22);
	auto backItem = MenuItemSprite::create(backnormal, backselected, CC_CALLBACK_1(PauseScene::menuCloseCallback, this));
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