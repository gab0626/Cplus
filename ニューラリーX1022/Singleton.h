#pragma once
#include "lib\framework.hpp"

#define env (App::Get())
#define WINDOW_WIDTH (2000)
#define WINDOW_HEIGHT (2000)

class App
{
private:

public:

	static AppEnv& Get()
	{
		static AppEnv s_env(WINDOW_WIDTH, WINDOW_HEIGHT, false, false);

		return s_env;
	}
};