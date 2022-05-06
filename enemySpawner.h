#pragma once
#include "object.h"

class EnemySpawner : public Object {
private:
	int i = 0;
	int randomSpawn = 60;

public:
	EnemySpawner() :Object() {};
	EnemySpawner(std::string fileName) :Object(fileName) { typeObject = BACKGROUND_OBJ; };
	virtual void step() override;
};