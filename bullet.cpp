#include "bullet.h"
#include "system.h"

void Bullet::step()
{
	this->position.x += direction.x * 0.01f;
    this->position.y+=direction.y*0.01f;
	
	//testColisiones
	
        std::vector<Object*> *enemies=System::scene->getCollisions(ENEMY_OBJ, this);
	
        if(enemies->size()>0)
	{
		System::scene->deleteObject(this);
		for(auto it=enemies->begin();it!=enemies->end();it++)
			System::scene->deleteObject(*it);
	
        }

		//TODO colisiones con player
		std::vector<Object*>* objects = System::scene->getCollisions(SPACESHIP_OBJ, this);

		if (objects->size() > 0)
		{
			System::scene->deleteObject(this);
			for (auto it = objects->begin(); it != objects->end(); it++)
				System::scene->deleteObject(*it);

		}
		else if ((this->position.y > 2.0f) || (this->position.y < -2.0f))
		{
			System::scene->deleteObject(this);
		}
}


