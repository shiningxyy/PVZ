#pragma once
#include"card.h"
#include "ui/CocosGUI.h"
using namespace ui;
class Sunflowercard :public Card {
public:
	Sunflowercard() {
		this->card_init();
		this->scheduleUpdate();
	};
	~Sunflowercard() = default;
	virtual void card_init();//初始化
	virtual void cold_animation();//卡片冷却动画
	virtual void update(float);
	float timecount;//计时器
	
};