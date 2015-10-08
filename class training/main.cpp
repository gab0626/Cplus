#include "lib/framework.hpp"
#include "class.h"
#include "sceneManager.h"
#include "singleton.h"

int main() {

	env;

  SceneManager scenemanager;

  while (env.isOpen()) {
	  scenemanager.Shift();

	  scenemanager.upDate();

    env.begin();
    
	scenemanager.Draw();

    env.end();
  }
}
