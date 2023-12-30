#pragma once
#include"plant.h"

#define CHERRY_BLOOD 0
#define CHERRY_RATE 0

class Cherrybomb :public Plant {
public:
	Cherrybomb() { init_plant(); };
	~Cherrybomb() = default;
	virtual void init_plant();//初始化植物属性
	virtual void init_animation();//植物动画
	virtual void delete_();//删除植物

};
