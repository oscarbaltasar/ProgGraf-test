#pragma once
#include "object.h"




class SpaceShip: public Object{
private:
	bool pressedT = false;
	bool pressedY = false;
	int fireType = 1;
	// 0 = Normal, 1 = Shotgun, 2 = Double
public:
	SpaceShip(std::string fileName):Object(fileName){typeObject=SPACESHIP_OBJ;};
	virtual void step() override;
	void shoot(float x, float y, float rot, glm::vec3 scale, glm::vec2 dir);
};
