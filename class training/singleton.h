#pragma once
#include "lib\framework.hpp"

#define env (App::Get())

#define WIN_WIDTH (2048)
#define WIN_HEIGHT (1024)

class App
{
private:

public:

	static AppEnv& Get()
	{
		static AppEnv s_env(WIN_WIDTH, WIN_HEIGHT, false, true);

		return s_env;
	}
};