#pragma once
#include"plant.h"

#define CHERRY_BLOOD 300
#define CHERRY_RATE 10

class Cherrybomb :public Plant {
public:
	Cherrybomb() { init_plant(); };
	~Cherrybomb() = default;
	virtual void init_plant();//初始化植物属性
	virtual void init_animation();//植物动画
	virtual void update(float);//删除植物

};
