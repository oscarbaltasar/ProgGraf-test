#include "enemySpawner.h"
#include "system.h"
#include "enemy.h"

void EnemySpawner::step()
{
	i++;
	if (i % randomSpawn == 0) {
		randomSpawn = rand() % 70 + 50;
		Enemy* enemy = new Enemy("bullet.trg");
		enemy->scale = this->scale;
		enemy->position.y = this->position.y;
		enemy->rotation.z = this->rotation.z;
		System::scene->addObject(enemy);
	}
}
