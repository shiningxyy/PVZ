#ifndef _CAR_H_
#define _CAR_H_
#include "cocos2d.h"
using namespace cocos2d;

class Car : public Node {
public:
	Car() = default;
	~Car() = default;
	virtual bool init();
	void setstate(int);
	void setrow(int);
	int getstate() const;
	void runaction();
	virtual void update(float);
	Vec2 getposition() const; 
	float getx() const; 
	float gety() const;
	CREATE_FUNC(Car);

protected:
	Sprite* car;
	int state; 
	int row=0;
};
#endif // _CAR_H_
