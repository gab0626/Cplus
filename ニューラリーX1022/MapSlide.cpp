#include "MapSlide.h"
#include "Map.h"
#include "lib\framework.hpp"



MapSlide::MapSlide()
{

};


void MapSlide::SetUp()
{

};

void MapSlide::Draw()
{

	if (env.isPushKey(GLFW_KEY_LEFT) && MapMoveLeft == false)
	{
		MapMoveLeft = true;
		MapMoveRight = false;
		MapUp = false;
		MapDown = false;
	}

	if (env.isPushKey(GLFW_KEY_RIGHT) && MapMoveRight == false)
	{
		MapMoveRight = true;
		MapMoveLeft = false;
		MapUp = false;
		MapDown = false;
	}

	if (env.isPushKey(GLFW_KEY_UP) && MapUp == false)
	{
		MapUp = true;
		MapDown = false;
		MapMoveRight = false;
		MapMoveLeft = false;
	}

	if (env.isPushKey(GLFW_KEY_DOWN) && MapDown == false)
	{
		MapUp = false;
		MapDown = true;
		MapMoveRight = false;
		MapMoveLeft = false;
	}

	
};