#pragma once
#include"plant.h"

#define SUNFLOWER_BLOOD 300
#define SUNFLOWER_RATE 10

class Sunflower :public Plant {
public:
	Sunflower() { init_plant(); };
	~Sunflower() = default;
	virtual void init_plant();//初始化植物属性
	virtual void init_animation();//植物动画
	virtual void delete_();//删除植物


};
