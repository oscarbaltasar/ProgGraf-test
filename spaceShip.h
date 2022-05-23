#pragma once
#include "object.h"




class SpaceShip: public Object{
private:
	bool pressedT = false;
	bool pressedY = false;
	// 0 = Normal, 1 = Shotgun, 2 = Double
	int fireType = 0;
	int parryCoolDown = 0;
public:
	SpaceShip(std::string fileName):Object(fileName){typeObject=SPACESHIP_OBJ;};
	virtual void step() override;
	virtual void hitResponse() override;
	void shoot(float x, float y, float rot, glm::vec3 scale, glm::vec2 dir);
	void addCoolDown(int i);
	void setFireType(int fire);
};
