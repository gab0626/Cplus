#pragma once
#include "lib\framework.hpp"
#include"Singleton.h"

enum MAP
{
	BLOCK_SIZE = 100,
	MAX_WIDTH = 50,
	MAX_HEIGHT = 35

};



class Map
{
private:

	Texture StageChip;

public:

	Map();

	Vec2f pos = Vec2f(1000,-1000);

	void SetUp();
	void Draw();
	int Stage[35][50];
	bool MapDown = true;
	bool MapUp = false;
	bool MapMoveLeft = false;
	bool MapMoveRight = false;
};