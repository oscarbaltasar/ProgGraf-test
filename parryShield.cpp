#include "parryShield.h"
#include "system.h"

void ParryShield::setPlayer(SpaceShip* player)
{
	this->player = player;
}

void ParryShield::step()
{
	wait--;
	if (wait == 0) {
		player->addCoolDown(120);
		System::scene->deleteObject(this);
	}
}

void ParryShield::hitResponse()
{
	//std::cout << "Buen Parry";
}
