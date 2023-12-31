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

void Car::setstate(int s)
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
	this->runAction(Sequence::create(MoveBy::create(4, Vec2(1000, 0)), RemoveSelf::create(), nullptr));

}

Vec2 Car::getposition() const
{
	return this->getPosition();
}
float Car::getx() const
{
	return car->getPositionX();
}
float Car::gety() const
{
	return car->getPositionY();
}