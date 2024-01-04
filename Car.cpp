#include "Car.h"
USING_NS_CC;

bool Car::init()
{
	if (!Node::init())
	{
		return false;
	}
	car = Sprite::create("car.png");
	this->addChild(car);
	return true;
}

void Car::setstate(int s)//·µ»Ø
{
	state = s;
}
void Car::setrow(int r)
{
	row = r;
}
int Car::getstate() const
{
	return state;
}
void Car::runaction()
{
	car->runAction(MoveBy::create(4, Vec2(1030, 0)));

}

Vec2 Car::getposition() const
{
	return car->getPosition();
}
float Car::getx() const
{
	return car->getPositionX();
}
float Car::gety() const
{
	return car->getPositionY();
}

