#pragma once
#include"card.h"
#include "ui/CocosGUI.h"
using namespace ui;
class Cherrybombcard :public Card {
public:
	Cherrybombcard() {
		this->card_init();
		this->scheduleUpdate();
	};
	~Cherrybombcard() = default;
	virtual void card_init();//初始化
	virtual void cold_animation();//卡片冷却动画
	virtual void update(float);
	float timecount;//计时器
};