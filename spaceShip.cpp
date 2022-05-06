#include "spaceShip.h"
#include "inputManager.h"
#include "scene.h"
#include "system.h"
#include "bullet.h"

void SpaceShip::step()
{


	if(InputManager::keys['A'])
	{
                position.x-=0.01f;
	}	

	if(InputManager::keys['D'])
	{
                position.x+=0.01f;
	}
	
	if(InputManager::keys['T'])
	{ 	
		if (!pressedT) {
			pressedT = true;

			glm::vec3 scale;
			switch (fireType) {
			case 0:
				scale = glm::vec3(0.075f, 0.075f, 0.075);
				this->shoot(0, 0, 0, scale, glm::vec2(0.0f,1.0f));
				break;
			case 1:
				scale = glm::vec3(0.05f, 0.05f, 0.05);
				this->shoot(0, 0.005f, 0, scale, glm::vec2(0.0f, 1.5f));
				this->shoot(0.005f, 0, glm::radians(-5.0f), scale, glm::vec2(0.25f, 1.5f));
				this->shoot(-0.005f, 0, glm::radians(5.0f), scale, glm::vec2(-0.25f, 1.5f));
				break;
			}
			
			
		}
	}
	else {
		pressedT = false;
	}

	
}

void SpaceShip::shoot(float x, float y, float rot, glm::vec3 scale, glm::vec2 dir) {
	Bullet* bullet = new Bullet("bullet.trg");
	bullet->position.x = this->position.x + x;
	bullet->position.y = this->position.y + 0.15f + y;
	bullet->rotation.z = this->rotation.z - glm::radians(180.0f) + rot;
	bullet->scale = scale;
	bullet->direction = dir;
	System::scene->addObject(bullet);
}
