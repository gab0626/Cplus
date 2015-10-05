//
// アプリ雛形
// 
// VisualStudioでもコンパイルできるようにするため
// ソースコードをUTF-8(BOM付き)で用意:D
//

// Frameworkの全てをインクルード
#include "lib/framework.hpp"
#include "training.h"
#include "graffic.h"
#include <iostream>


// アプリのウインドウサイズ
enum Window {
	WIDTH = 1080,
	HEIGHT = 720
};



int main() {
 
  AppEnv env(Window::WIDTH, Window::HEIGHT);

  Texture text("res/test.png");


  Vec2f pos = Vec2f(0, 0);
  Vec2f size = Vec2f(1024, 1024);
  Vec2f pick = Vec2f(0, 0);
  Vec2f drawsize = Vec2f(1024, 1024);



  while (env.isOpen()) {
    // 開始
    env.begin();

	graffic(pos, size, text);
    
    env.end();
  }
}
