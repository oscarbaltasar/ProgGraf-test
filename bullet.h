#pragma once
#include "object.h"

class Bullet: public Object{

	
public:
	glm::vec2 direction= glm::vec2(0.0f, 1.0f);

	Bullet():Object(){};
        Bullet(std::string fileName):Object(fileName){typeObject=BULLET_OBJ;};
	virtual void step() override;
};

