#pragma once
/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "cocos2d.h"
#include<string>
#include "ui/CocosGUI.h"
#include"plant.h"
USING_NS_CC;

enum CardType {
	SUNFLOWER_CARD,//太阳花0
	PEASHOOTER_CARD,//豌豆射手1
	WALLNUT_CARD,//坚果墙2
	SQUASH_CARD,//窝瓜3
	CHERRYBOMB_CARD//樱桃炸弹4
};

class Card :public Sprite {
public:
	//成员
	double card_cd;//卡片冷却时间
	Sprite* sprite;//精灵
	Sprite* cd_sprite;
	int sunnum;//阳光总量
	int cost;//价格
	FadeIn* cardfade;//卡片冷却动画
	bool choose;//是否被选择
	Rect rect;
	bool cold;//判断冷却
	CardType ct;//卡片类型
	//函数
	Card() = default;
	~Card() = default;
	bool is_choose();//判断是否被选中
	bool is_cold();//判断是否处于冷却状态
	Rect getrect();//获取卡片范围
	void getsun(int);//获取阳光数量
	void sprite_init(std::string, Vec2);//初始化精灵
	void cd_sprite_init(std::string, Vec2);
	virtual void card_init() {};
	virtual void cold_animation() {};
	virtual void move_animation(Vec2&);//卡片移动动画
};