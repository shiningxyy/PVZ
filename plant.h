#pragma once
/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "cocos2d.h"
#include<string>
USING_NS_CC;

enum PlantType {
    NONE = -1,//没种植物
    SUNFLOWER,//太阳花0
    PEASHOOTER,//豌豆射手1
    WALLNUT,//坚果墙2
    CHERRYBOMB//樱桃炸弹3
};

class Plant :public Sprite {
public:
    Plant() = default;
    ~Plant() = default;
    virtual void init_plant() {};//初始化植物信息
    virtual Sprite* init_sprite(Vec2);//精灵初始化
    virtual void set_blood(int);//设置血量
    virtual void set_interval(float);//设置时间间隔
    virtual float get_interval();//获取时间间隔
    virtual void is_plant(bool);//设置是否种植
    virtual void is_shoot(bool);//是否发射子弹
    virtual void attacked(int);//被攻击后扣除血量
    virtual int get_blood();//获取当前血量
    virtual void set_type(PlantType);//设置植物类型
    virtual PlantType get_type();//获取植物类型
    virtual void init_animation();//初始化植物动画
    virtual void set_firstframe(SpriteFrame*);//设置第一帧动画
    virtual void load_animation(std::string, int, cocos2d::Vector<cocos2d::SpriteFrame*>&);//加载动画
    virtual void set_animation(Animate*);//获取植物动画
    virtual Sprite* run_animation(Vec2);//植物种下后的动画
    virtual Animate* get_animation() { return panimate; };
    virtual void set_size(double);//设置大小
    virtual void set_rate(double);
    virtual double get_rate();
    virtual int get_row() { return row; };
    virtual int get_col() { return col; };
    virtual float get_x() { return pos.x; };
    virtual float get_y() { return pos.y; };
    virtual Vec2 get_pos() { return pos; };
    virtual Rect get_rect();
    virtual Sprite* get_sprite() { return this->sprite; };
    double time_count;
    double rate_time;
    int row;
    int col;
private:
    int blood;//血量
    bool planted;//是否被种植
    bool shooted;//是否发射子弹
    Sprite* sprite;//精灵
    PlantType pt;//植物类型
    SpriteFrame* firstframe;//第一帧动画
    Animate* panimate;//植物动画
    Vec2 pos;//位置
    Rect rect;
    float interval;//时间间隔
 
   
   
};