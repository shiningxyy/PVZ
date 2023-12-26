#pragma once
#include"plant.h"

#define SQUASH_BLOOD 300
#define SQUASH_RATE 0

class Squash :public Plant {
public:
	Squash() { init_plant(); };
	~Squash() = default;
	virtual void init_plant();//初始化植物属性
	virtual void init_animation();//植物动画
	virtual void delete_();//删除植物
	virtual void attack_animation();//攻击动画

};
