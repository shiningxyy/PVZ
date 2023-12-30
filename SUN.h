#ifndef  _SUN_H_
#define  _SUN_H_
#include<vector>
#include "cocos2d.h"

USING_NS_CC;
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#define  X_MAX 900
#define  Y_MAX 600
#define  sky 0
#define  sunflower 1
class SUN :public cocos2d::Sprite
{
protected:
    int num_sun;//屏幕上存在阳光的数量
    double time_sun;//阳光保留时间
    int collection;//收集到的阳光
    Sprite* sunsprite;
    //判断太阳花，然后太阳跳出
    void move_1() ;
    void producesun();
    void move_2();
    void collectsun();
public:
    void onMouseDown(Event* event);
    SUN();
    SUN(int);
    ~SUN();//到达阳光保留时间，自动渐变消失
    void start_move() {
        producesun();
        move_1();   //掉落+旋转（animate）+停止
    }
    void collected_callback()
    {
        collectsun();
    }//onMouseDown鼠标按下，然后callback，之后不接受
    void jump(Vec2& position_);
};

#endif