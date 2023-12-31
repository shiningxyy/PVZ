#ifndef  _BULLET_H_
#define  _BULLET_H_
#include "cocos2d.h"
USING_NS_CC;

//生成+撞到僵尸（每一行遍历，找到最前面x_min）——回调函数+造成伤害+消失
//向日葵豌豆射手
class Bullet : public Node {
public:
	Bullet();
	~Bullet() = default;
	virtual bool bullet_init();// 初始化

	virtual void bullet_move(); //子弹移动
	virtual void bullet_explode(); //子弹移动
	void sprite_init(const Vec2& pos);
	virtual Vec2 getposition() const; // 获取二维坐标
	virtual double getx() const; // getPositionX
	virtual double gety() const;
	virtual void set_crash(); // 设置为判断
	virtual bool judge_crash(); // crash judgement, if ture, delete the bullet
	virtual void set_attack_num(double damage);// 设置子弹伤害
	virtual void delete_sprite(); // 删除精灵 
	int row;
	//变量
	Vec2 position; // 二维坐标
	Sprite* bulletsprite; //精灵变量
	double attack_num; // 攻击伤害
	bool is_crash; // 是否碰撞   true:碰撞  false：未碰撞
	Animate* bullet_explode_animate;
};



#endif