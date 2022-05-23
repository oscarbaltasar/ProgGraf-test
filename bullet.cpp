#include "bullet.h"
#include "system.h"
#include "item.h"

void Bullet::step()
{
	this->position.x += direction.x * 0.01f;
    this->position.y+=direction.y*0.01f;
	
	//testColisiones
	
        std::vector<Object*> *enemies=System::scene->getCollisions(ENEMY_OBJ, this);
	
        if(enemies->size()>0)
	{
		System::scene->deleteObject(this);
		for (auto it = enemies->begin(); it != enemies->end(); it++) {
			int random = ((int)rand()) % 100;
			if (random <= 5) {
				Item* item = new Item("item.trg");
				item->direction = glm::vec2(0.0f, -0.5f);
				item->rotation.z = (*it)->rotation.z;
				item->position.x = (*it)->position.x;
				item->position.y = (*it)->position.y - 0.25f;
				item->scale = glm::vec3(0.1f, 0.1f, 0.1f);
				System::scene->addObject(item);
			}
			System::scene->deleteObject(*it);
		}
	
        }

		//TODO colisiones con player
		std::vector<Object*>* objects = System::scene->getCollisions(SPACESHIP_OBJ, this);

		if (objects->size() > 0)
		{
			System::scene->deleteObject(this);
			for (auto it = objects->begin(); it != objects->end(); it++) {
				(*it)->hitResponse();
				System::scene->deleteObject(*it);
			}

		}
		else if ((this->position.y > 2.0f) || (this->position.y < -2.0f))
		{
			System::scene->deleteObject(this);
		}
}


