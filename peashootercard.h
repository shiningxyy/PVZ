#pragma once
#include"card.h"
#include "ui/CocosGUI.h"
using namespace ui;
class Peashootercard :public Card {
public:
	Peashootercard() {
		this->card_init();
		sprite = Sprite::create();
		sprite->setColor(Color3B::GRAY);
		this->scheduleUpdate();
	};
	~Peashootercard() = default;
	virtual void card_init();//初始化
	virtual void cold_animation();//卡片冷却动画
	virtual void update(float);
	float timecount;//计时器
};