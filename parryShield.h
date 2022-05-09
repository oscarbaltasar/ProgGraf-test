#pragma once
#include "object.h"
#include "spaceShip.h"

class ParryShield : public Object {
private:
	int wait = 10;
	SpaceShip* player;

public:

	ParryShield() :Object() {};
	ParryShield(std::string fileName) :Object(fileName) { typeObject = SPACESHIP_OBJ; };
	void setPlayer(SpaceShip* player);
	virtual void step() override;
	virtual void hitResponse() override;
};