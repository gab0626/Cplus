#include "lib/framework.hpp"
#include "Editor.h"
#include "Singleton.h"


int main() {
 
  env;

  Editor editor;

  while (env.isOpen()) {
    
	  editor.SetUp();

    env.begin();

	editor.Draw();

    env.end();
  }
}
