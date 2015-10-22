#pragma once
#include "lib\framework.hpp"
#include "Singleton.h"
#include "Map.h"

class MapSlide
{
private:

public:

	MapSlide();

	void SetUp();
	void Draw();

	bool MapDown = true;
	bool MapUp = false;
	bool MapMoveLeft = false;
	bool MapMoveRight = false;

};