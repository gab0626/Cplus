#include "lib/framework.hpp"
#include "Class.h"
#include "Singlton.h"
#include "SceneManager.h"
 
int main() {
	env;

	Font font("res/msgothic.ttc");
	font.size(50);

	enum {
		TITLE,
		STAGE1,
		RESULT
	};

	int e = 0;

  while (env.isOpen()) {
	  
    env.begin();

	if (!env.isOpen())
	{
		return 0;
	}

	switch (e)
	{
	case TITLE:
		font.draw("ニューラリーX", Vec2f(500, 500),Color::white);
		break;

	case STAGE1:
		font.draw("ステージ１", Vec2f(500,500), Color::white);
		break;
	case RESULT:
		font.draw("リザルト", Vec2f(504, 502), Color::white);
		break;
	}
	

	if (env.isPushButton(Mouse::LEFT))
	{
		e = (e + 1);
		if (e >= 3)
		{
			e = 0;
		}
	}


	
    env.end();
  }
}
