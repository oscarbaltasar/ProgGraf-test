#include <iostream>
#include "common.h"
#include <vector>
#include "mesh.h"
#include "render.h"
#include "object.h"
#include "scene.h"
#include "inputManager.h"
#include "spaceShip.h"
#include "system.h"

#include "enemy.h"
#include "cube.h"
#include "background.h"
#include "enemySpawner.h"



bool renderfps(double framerate) 
{ 
	static double currentTime = 0; 
	static double lastTime=0;
	
	currentTime = glfwGetTime();
	if(currentTime - lastTime >= 1.0 / framerate) 
	{
		lastTime = currentTime;
		return true;
	}
	return false;
}


int main(int argc, char** argv)
{

	int glfwState=glfwInit();
	if (!glfwState)
		std::cout << "ERROR iniciando glfw\n";

	GLFWwindow* window = glfwCreateWindow(640,480,"Prueba 1 GLFW",nullptr,nullptr);
	glfwMakeContextCurrent(window);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	
	int glewState=glewInit();
	
	if (glewState!=GLEW_OK)
		std::cout << "ERROR iniciando glew\n";

	InputManager::init(window);
	Object* triangle = new SpaceShip("triangle.trg");
	triangle->scale=glm::vec3(0.1f,0.1f,0.1f);
	triangle->position.y=-0.45f;
	
	
	Object* enemy=new Enemy("triangle.trg");
	enemy->scale=glm::vec3(0.1f,0.1f,0.1f);
	enemy->position.y=0.45f;
	enemy->rotation.z=glm::radians(180.0f);

	Object* enemySpawner = new EnemySpawner("triangle.trg");
	enemySpawner->scale = glm::vec3(0.1f, 0.1f, 0.1f);
	enemySpawner->position.y = 0.45f;
	enemySpawner->position.z = -1.0f;
	enemySpawner->rotation.z = glm::radians(180.0f);

	Background* background = new Background("background.trg");
	background->scale = glm::vec3(1.0f, 1.0f, 1.0f);
	background->position.y = 0.0f;
	background->position.z = -0.01f;
	

	Render* render=new Render();
	Scene* scene=new Scene();
	System::scene=scene;
	scene->setCamera(new Camera(glm::vec3(0,0,0.5),glm::vec3(0,0,0),perspective));
	scene->addLight(new Light(glm::vec4(-3.0, 0, 6.0, 1), glm::vec4(0, 0, 0, 1)));
	scene->addLight(new Light(glm::vec4(3.0, 0, 6.0, 1), glm::vec4(0, 0, 0, 1)));
	scene->addObject(background);
	scene->addObject(triangle);
	scene->addObject(enemy);
	scene->addObject(enemySpawner);
	
	render->setupObject(background);
	render->setupObject(enemy);
	render->setupObject(enemySpawner);
	render->setupObject(triangle);

	//Object* cube=new Cube("cube.trg");
	//cube->scale=glm::vec3(0.5f,0.5f,0.5f);
	//cube->position.z=3.0f;

	//render->setupObject(cube);
	//scene->addObject(cube);

	while(!glfwWindowShouldClose(window))
	{	
	
		if(renderfps(60.0f)){
			scene->step(0.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				render->drawScene(scene);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	
	//delete triangle;
	return 0;

}