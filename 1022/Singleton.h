#pragma once
#include "lib\framework.hpp"

#define env (App::Get())
#define WINDOW_WIDTH (1000)
#define WINDOW_HEIGHT (1000)

class App
{
private:

public:

	static AppEnv& Get()
	{
		static AppEnv s_env(WINDOW_WIDTH, WINDOW_HEIGHT, false, true);

		return s_env;
	}
};