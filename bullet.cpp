#include"bullet.h"

USING_NS_CC;


Bullet::Bullet() {
    bullet_init();
}

bool Bullet::bullet_init() {
    if (!Node::init())
        return false;
    // 初始化子弹
    attack_num = 0;
    is_crash = false;
    sprite_init(position);
    scheduleUpdate();
    return true;

}


void Bullet::bullet_explode() {
    bulletsprite->stopAllActions();//停止动作
    Animation* animation = Animation::create();
    animation->addSpriteFrameWithFile("pea.png");
    animation->addSpriteFrameWithFile("peaexplode.png");
    animation->setDelayPerUnit(0.1f);
    bullet_explode_animate = Animate::create(animation);
    bulletsprite->runAction(Repeat::create(bullet_explode_animate,1));
}//如果撞到，爆炸动画

void Bullet::bullet_move() {
    bulletsprite->runAction(MoveTo::create(3.0f, Vec2(1000, position.y)));//一直移动
}

void Bullet::sprite_init(const Vec2& pos) {
    // 初始化精灵
    bulletsprite = Sprite::create("pea.png");
    position = pos;
    bulletsprite->setPosition(position);
  
}

Vec2 Bullet::getposition() const {
    // 获取子弹的位置
    return this->getPosition();
}

double Bullet::getx() const {
    // 获取子弹的x坐标
    return this->getPositionX();
}

double Bullet::gety() const {
    // 获取子弹的y坐标
    return this->getPositionY();
}

void Bullet::set_crash() {
    // 设置子弹的碰撞状态
    is_crash = true;
}

bool Bullet::judge_crash() {
    // 判断子弹是否碰撞
    return is_crash;
}

void Bullet::set_attack_num(double damage) {
    // 设置子弹的伤害值
    attack_num = damage;
}

void Bullet::delete_sprite() {
    // 删除精灵
    bulletsprite->runAction( RemoveSelf::create());
    
}


