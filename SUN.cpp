#include"sun.h"
#include<string>
USING_NS_CC;

using namespace ui;
SUN::SUN() {
    num_sun = 0;//自己下落的数量
    time_sun=0.0;//阳光保留时间
    collection=0;//收集到的阳光
    sunsprite = Sprite::create("sun.png");//用太阳图片创建spirit
    
    //Layer::getInstance()->addChild(spSun, 202);
}
SUN::SUN(int producedby) {
    num_sun = 0;//自己下落的数量
    time_sun = 0.0;//阳光保留时间
    collection = 0;//收集到的阳光
    sunsprite = Sprite::create("sun.png");//用太阳图片创建spirit
  
    if (producedby == sky) {
        producesun();
        num_sun++;
    }
    if (producedby == sunflower) {

    }
}
SUN::~SUN() {
}
void SUN::jump(Vec2& position_) {
    sunsprite->setScale(0.2f);
    sunsprite->setPosition(position_.x, position_.y);
    auto fadeIn = FadeIn::create(1.0f);
    sunsprite->runAction(fadeIn);
}

void SUN::producesun() {
    sunsprite->setScale(0.2f);
    
    srand((unsigned int)(time(0)));
  
    sunsprite->setPosition(Vec2(rand()%X_MAX,Y_MAX-100));//位置随机，但是在上方
    /*auto listener1 = EventListenerMouse::create();
    listener1->onMouseDown = CC_CALLBACK_1(SUN::onMouseDown, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);*/
}
void SUN::move_1() {

   
    Vec2 position = sunsprite->getPosition();
    auto moveTo = MoveTo::create(2, Vec2(position.x, 30));

    auto rotateBy = RotateBy::create(2.0f, 360.0f);//规定的时间（？），除法

    auto fallSpawn = Spawn::createWithTwoActions(moveTo, rotateBy);//同时执行下落和旋转
    auto seq = Sequence::create(fallSpawn,nullptr);
    sunsprite->runAction(seq);
} //掉落+旋转（animate）+停止

void SUN::move_2() {
    sunsprite->stopAllActions();//停止动作
    sunsprite->setScale(0.2f);
    auto moveToup = MoveTo::create(1.5f, Vec2(40, Y_MAX-35));
    auto scaleTo = ScaleTo::create(1.0f, 0.1f);
    auto fadeOut = FadeOut::create(1.0f);
    auto removeSelf = RemoveSelf::create();
  

    auto seq = Sequence::create(moveToup,scaleTo, fadeOut, nullptr);

    sunsprite->runAction(seq);
}//飞到左上角，然后缩小，左上角坐标（0，ymax）

void SUN::onMouseDown(Event* event)
{
    //获取事件
    EventMouse* e = (EventMouse*)event;
    //获取元素
   // auto ui = this->getChildByTag(666);
   // auto button = ui->getChildByTag(4);
    //获取鼠标事件触发的坐标->限定按钮范围
   if (e->getCursorX() >= sunsprite->getPositionX() - 100 && e->getCursorX() <= sunsprite->getPositionX() + 100
        && e->getCursorY() >= sunsprite->getPositionY() - 60 && e->getCursorY() <= sunsprite->getPositionY() + 60)
    /*if (e->getCursorX() >= 0 && e->getCursorX() <= X_MAX
        && e->getCursorY() >= 0 && e->getCursorY() <= Y_MAX)*/
    {
        move_2();
        collection=1;
        num_sun--;
    }
   collection = std::min(1, collection);
}

void SUN::collectsun() {
   
}//监听鼠标事件（坐标对+按下左键），然后吞没鼠标事件，收集到的阳光+1，目前存在阳光-1