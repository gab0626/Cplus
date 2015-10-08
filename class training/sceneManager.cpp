#include "sceneManager.h"


SceneManager::SceneManager()
{

	scene_num = Title;

}


void SceneManager::upDate()
{
	switch (scene_num)
	{
	case Title:

		title.upDate();
		break;



	case Game:

		title.upDate();
		break;

	case Result:

		result.upDate();
		break;
	}

}

void SceneManager::Draw()
{

	switch (scene_num)
	{
	case Title:

		title.draw();
		break;



	case Game:

		game.draw();
		break;

	case Result:

		result.draw();
		break;
	}

}

void SceneManager::Shift()
{

	switch (scene_num)
	{
	case Title:

		if (env.isPushButton(Mouse::LEFT))
		{
			scene_num = title.Shift();
		}

		break;



	case Game:

		if (env.isPushButton(Mouse::LEFT))
		{
			scene_num = game.Shift();
		}

		break;

	case Result:

		if (env.isPushButton(Mouse::LEFT))
		{
			scene_num = result.Shift();
		}

		break;
	}

}