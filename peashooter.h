#pragma once
#include"plant.h"

#define PEASHOOTER_RATE 1.5f
#define PEASHOOTER_BLOOD 300

class Peashooter :public Plant {
public:
	Peashooter() { init_plant(); };
	~Peashooter() = default;
	virtual void init_plant();//初始化植物属性
	virtual void init_animation();//植物动画
	virtual void delete_(float);//删除植物

};
