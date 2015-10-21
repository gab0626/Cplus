#pragma once
#include "lib\framework.hpp"
#include "Singleton.h"

class Editor
{
public:

	Vec2f pos = env.mousePosition();

	int Map[30][50];
	void SetUp();
	void Draw();
};