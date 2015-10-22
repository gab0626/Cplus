#include "lib/framework.hpp"
#include "Map.h"
#include "MapSlide.h"



int main() {

  env;
  Texture StageChip("res/Stagechip.png");
  Map map;
  MapSlide mapslide;
	
  map.SetUp();

  while (env.isOpen()) {

	  
    
    env.begin();

	mapslide.Draw();
	map.Draw();

    env.end();
  }
}
