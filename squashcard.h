#pragma once
#include"card.h"
#include "ui/CocosGUI.h"
using namespace ui;
class Squashcard :public Card {
public:
	Squashcard() {
		this->card_init();
		this->scheduleUpdate();
	};
	~Squashcard() = default;
	virtual void card_init();//初始化
	virtual void cold_animation();//卡片冷却动画
	virtual void update(float);
	float timecount;//计时器
};