#pragma once
#include "lib\framework.hpp"
#include "class.h"
#include "singleton.h"

class SceneManager
{
private:

	title title;
	game game;
	result result;

	SceneName scene_num;

public:

	SceneManager();

	void upDate();
	void Draw();
	void Shift();

};