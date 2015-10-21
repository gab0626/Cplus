#include "lib/framework.hpp"
#include "Map.h"



int main() {

  env;

  Map map;
	
  map.SetUp();

  while (env.isOpen()) {

	  
    
    env.begin();

	map.Draw();

    env.end();
  }
}
