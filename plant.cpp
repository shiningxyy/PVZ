#include"plant.h"

Sprite* Plant::init_sprite(Vec2 pos0) {
    //Size show_ran = Director::getInstance()->getVisibleSize();

    sprite = Sprite::createWithSpriteFrame(firstframe);
    sprite->setPosition(pos0);
    pos = pos0;
    return this->sprite;
}
void Plant::set_blood(int b) {
    blood = b;
}
void Plant::attacked(int a) {
    blood -= a;
}
int Plant::get_blood() {
    return blood;
}
void Plant::set_interval(float t) {
    interval = t;
}
float Plant::get_interval() {
    return interval;
}
void Plant::is_plant(bool p) {
    planted = p;
}
void Plant::is_shoot(bool s) {
    shooted = s;
}
void Plant::set_type(PlantType p) {
    pt = p;
}
PlantType Plant::get_type() {
    return pt;
}
void Plant::set_firstframe(SpriteFrame* ff) {
    firstframe = ff;
}
void Plant::set_animation(Animate* a) {
    panimate = a;
}
void Plant::load_animation(std::string s, int n, cocos2d::Vector<cocos2d::SpriteFrame*>& sf) {
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(s);
    auto cache = SpriteFrameCache::getInstance();
    int i = s.size();
    int j = i;
    while (s[i] != '/') {//循环向前搜索，直到找到路径中的最后一个斜杠
        if (s[i] == '_')
            j = i;
        i--;
    }
    i++;
    std::string s1 = s.substr(i, j - i);
    for (int k = 1; k <= n; k++) {//使用循环加载动画帧
        std::string name = s1 + std::to_string(k) + ".png";
        auto temp = cache->getSpriteFrameByName(name + std::to_string(i) + ".png");
        sf.pushBack(temp);
    }
    return;
}
Sprite* Plant::run_animation(Vec2 posi) {
    init_animation();
    auto plant = init_sprite(posi);
    plant->runAction(RepeatForever::create(this->get_animation()));
    set_size(1.85);
    return plant;
}
void Plant::init_animation() {}
void Plant::set_size(double s) {
    this->sprite->setScale(s);
}
void Plant::set_rate(float r) {
    rate = r;
}
float Plant::get_rate() {
    return rate;
}
Rect Plant::get_rect() {
    //左上角x坐标
    float cardx = this->sprite->getPosition().x -
        this->sprite->getContentSize().width * this->sprite->getAnchorPoint().x;
    //左上角y坐标
    float cardy = this->sprite->getPosition().y -
        this->sprite->getContentSize().height * this->sprite->getAnchorPoint().y;
    float w = this->sprite->getContentSize().width;//宽度
    float h = this->sprite->getContentSize().height;//高度
    return Rect(cardx, cardy, w, h);
}