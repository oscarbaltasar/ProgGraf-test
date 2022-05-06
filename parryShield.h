#pragma once
#include "object.h"

class ParryShield : public Object {
private:
	int wait = 10;

public:

	ParryShield() :Object() {};
	ParryShield(std::string fileName) :Object(fileName) { typeObject = SPACESHIP_OBJ; };
	virtual void step() override;
};