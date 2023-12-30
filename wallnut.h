#pragma once
#include"plant.h"

#define WALLNUT_BLOOD 1000
#define WALLNUT_RATE 10

class Wallnut :public Plant {
public:
	Wallnut() { init_plant(); };
	~Wallnut() = default;
	virtual void init_plant();//初始化植物属性
	virtual void init_animation();//植物动画
	virtual void delete_();//删除植物
	
};
