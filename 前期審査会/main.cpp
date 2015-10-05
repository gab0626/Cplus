#include "lib/framework.hpp"

int main() {
	AppEnv env(3800, 2050,
		false, true);

	//画像情報
	Font font("res/msgothic.ttc");
	Texture image("res/haikei.png");
	Texture image2("res/ryama.png");
	Texture image3("res/girl.png");
	Texture image4("res/title.png");
	Texture image5("res/title2.png");
	Texture image6("res/life.png");
	Texture image7("res/girl_under.png");
	Texture image8("res/girl_right.png");
	Texture image9("res/girl_left.png");
	Texture image10("res/girl_up.png");



	//音楽情報
	Media sound("res/daijyoubu.wav");
	Media sound2("res/db.wav");
	Media sound3("res/don.wav");
	Media sound4("res/kamiha.wav");
	Media sound5("res/mgs.wav");
	Media sound6("res/yubi.wav");
	Media sound7("res/lama to girl.wav");
	Media sound8("res/field.wav");
	Media sound9("res/fall.wav");
	Media sound10("res/naguru.wav");

	//変数情報
	int   fall = 0;
	int   i = 0;
	float right = -2100;
	float up = 1000;
	float title = 1025;
	float girl_x = -1000;
	float girl_x1 = -1980;
	float girl_x2 = -1460;
	float girl_x3 = -1180;
	float girl_x4 = -650;
	float girl_x5 = -900;
	float girl_x6 = -450;
	float girl_x7 = 650;
	float girl_x8 = 900;
	float girl_x9 = -200;
	float girl_x10 = 1600;
	float girl_x11 = 1600;
	float girl_y1 = 1024;
	float girl_y2 = -1300;
	float girl_y3 = 1200;
	float girl_y4 = -1300;
	float girl_y5 = 0;
	float girl_y6 = 800;
	float girl_y7 = -500;
	float girl_y8 = -400;
	float girl_y9 = -1010;
	float girl_y10 = -1300;
	float girl_y11 = 1100;
	bool hit_fg = false;


	//再生
	sound7.play();
	sound.pitch(1.0);
	sound7.looping(true);
	sound8.looping(true);
	//タイトル画面情報
	while (1){
		env.begin();
		while (2){
			env.begin();

			if (!env.isOpen()){
				return 0;
			}

			font.size(100);

			//背景画像
			drawTextureBox(-1900, -1025, 3800, 2050, 0, 0, 4096, 2048, image4);
			drawTextureBox(girl_x1, girl_y1, 1024, 1024, 0, 0, 1024, 1024, image3);

			//タイトル表示
			font.draw("リャマと女の子", Vec2f(-400, title), Color::white);

			if (env.isOpen()){
				title -= 10;
			}
			if (title < 0){
				title = 0;
			}
			if (title == 0){
				font.draw("左クリックしてね", Vec2f(-400, -200), Color::white);
			}
			if (girl_x > 3800){
				girl_x = -1100;
			}

			//左クリックでタイトルの音楽を止めて
			//次の音楽を再生
			if (env.isPushButton(Mouse::LEFT)){
				sound7.stop();
				break;
			}
			env.end();
		}
		while (4){
			env.begin();
			if (!env.isOpen()){
				return 0;
			}
			font.size(100);
			font.draw("概要説明", Vec2f(-900, 900), Color::white);
			font.draw("リャマという生物を操作してゴールを目指せ", Vec2f(-900, 700), Color::white);
			font.draw("Aキーで右、Dキーで左、Wキーで上、Sキーで下に移動", Vec2f(-900, 400), Color::white);
			font.draw("Gボタンでゲームスタート", Vec2f(-900, 0), Color::white);

			if (env.isPushKey('G')){
				sound6.play();
				sound8.play();
				break;
			}
			env.end();
		}
		while (3) {
			env.begin();
			if (!env.isOpen()){
				return 0;
			}

			//背景
			drawTextureBox(-2048, -1024, 4096, 2048, 0, 0, 3300, 2048, image);
			
			//ステージ
			drawFillBox(-2048, -1024, 300, 2048, Color::white);
			drawFillBox(-1748, -1024, 500, 150, Color::white);
			drawFillBox(-1448, -1024, 200, 2048, Color::white);
			drawFillBox(-1448, 1024, 400, -250, Color::white);
			drawFillBox(-1100, 1024, 150, -800, Color::white);
			drawFillBox(-1099, 350, 150, -1224, Color::white);
			drawFillBox(-1099, -1024, 500, 150, Color::white);
			drawFillBox(-599, -1024, 150, 1000, Color::white);
			drawFillBox(-599, -24, 400, 150, Color::white);
			drawFillBox(-199, -24, 150, 800, Color::white);
			drawFillBox(-199, 924, 900, -150, Color::white);
			drawFillBox(700, 924, 150, -1324, Color::white);
			drawFillBox(850, -300, -700, -150, Color::white);
			drawFillBox(150, -450, 150, -500, Color::white);
			drawFillBox(150, -1100, 1550, 200, Color::white);
			drawFillBox(1674, -1100, 125, 2048, Color::white);


			if (right >= -1848 && right <= -1600 && up <= 1024 && up>=800){
				right = -2100;
			}


			//ステージから落ちた最初から
			if (right > -1848 && right <= -1600){
				if (up < 800 && up >= -900){
					fall++;
					girl_y1 = 1100;
					girl_y2 = -1300;
					girl_y3 = 1200;
					girl_y4 = -1300;
					girl_y5 = 0;
					girl_y6 = 800;
					girl_y7 = -500;
					girl_y8 = -400;
					girl_y9 = -1010;
					girl_y10 = -1300;
					girl_y11 = 1100;
					girl_x5 = -900;
					girl_x6 = -450;
					girl_x7 = 650;
					girl_x8 = 900;
					girl_x9 = -200;
					up = 1000;
					right = -2100;
					sound9.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}

			if (right > -1348 && right <= -1200){
				if (up > -1024 && up <= 700){
					fall++;
					girl_y1 = 1100;
					girl_y2 = -1300;
					girl_y3 = 1200;
					girl_y4 = -1300;
					girl_y5 = 0;
					girl_y6 = 800;
					girl_y7 = -500;
					girl_y8 = -400;
					girl_y9 = -1010;
					girl_y10 = -1300;
					girl_y11 = 1100;
					girl_x5 = -900;
					girl_x6 = -450;
					girl_x7 = 650;
					girl_x8 = 900;
					girl_x9 = -200;
					up = 1000;
					right = -2100;
					sound9.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;

					}
				}
			}

			if (right > -1000 && right <= -700){
				if (up < 1000 && up >= -900){
					fall++;
					girl_y1 = 1100;
					girl_y2 = -1300;
					girl_y3 = 1200;
					girl_y4 = -1300;
					girl_y5 = 0;
					girl_y6 = 800;
					girl_y7 = -500;
					girl_y8 = -400;
					girl_y9 = -1010;
					girl_y10 = -1300;
					girl_y11 = 1100;
					girl_x5 = -900;
					girl_x6 = -450;
					girl_x7 = 650;
					girl_x8 = 900;
					girl_x9 = -200;
					up = 1000;
					right = -2100;
					sound9.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}

			if (right > -599 && right <= 0){
				if (up > -1024 && up <= -24){
					fall++;
					girl_y1 = 1100;
					girl_y2 = -1300;
					girl_y3 = 1200;
					girl_y4 = -1300;
					girl_y5 = 0;
					girl_y6 = 800;
					girl_y7 = -500;
					girl_y8 = -400;
					girl_y9 = -1010;
					girl_y10 = -1300;
					girl_y11 = 1100;
					girl_x5 = -900;
					girl_x6 = -450;
					girl_x7 = 650;
					girl_x8 = 900;
					girl_x9 = -200;
					up = 1000;
					right = -2100;
					sound9.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}

			if (right > -699 && right <= -300){
				if (up > 50 && up <= 1024){
					fall++;
					girl_y1 = 1100;
					girl_y2 = -1300;
					girl_y3 = 1200;
					girl_y4 = -1300;
					girl_y5 = 0;
					girl_y6 = 800;
					girl_y7 = -500;
					girl_y8 = -400;
					girl_y9 = -1010;
					girl_y10 = -1300;
					girl_y11 = 1100;
					girl_x5 = -900;
					girl_x6 = -450;
					girl_x7 = 650;
					girl_x8 = 900;
					girl_x9 = -200;
					up = 1000;
					right = -2100;
					sound9.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}

			if (right > -199 && right <= 550){
				if (up > -300 && up <= 700){
					fall++;
					girl_y1 = 1100;
					girl_y2 = -1300;
					girl_y3 = 1200;
					girl_y4 = -1300;
					girl_y5 = 0;
					girl_y6 = 800;
					girl_y7 = -500;
					girl_y8 = -400;
					girl_y9 = -1010;
					girl_y10 = -1300;
					girl_y11 = 1100;
					girl_x5 = -900;
					girl_x6 = -450;
					girl_x7 = 650;
					girl_x8 = 900;
					girl_x9 = -200;
					up = 1000;
					right = -2100;
					sound9.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}

			if (right > 750 && right <= 1500){
				if (up > -890 && up <= 800){
					fall++;
					girl_y1 = 1100;
					girl_y2 = -1300;
					girl_y3 = 1200;
					girl_y4 = -1300;
					girl_y5 = 0;
					girl_y6 = 800;
					girl_y7 = -500;
					girl_y8 = -400;
					girl_y9 = -1010;
					girl_y10 = -1300;
					girl_y11 = 1100;
					girl_x5 = -900;
					girl_x6 = -450;
					girl_x7 = 650;
					girl_x8 = 900;
					girl_x9 = -200;
					up = 1000;
					right = -2100;
					sound9.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}

			if (right > 170 && right <= 850){
				if (up < -450 && up >= -900){
					fall++;
					girl_y1 = 1100;
					girl_y2 = -1300;
					girl_y3 = 1200;
					girl_y4 = -1300;
					girl_y5 = 0;
					girl_y6 = 800;
					girl_y7 = -500;
					girl_y8 = -400;
					girl_y9 = -1010;
					girl_y10 = -1300;
					girl_y11 = 1100;
					girl_x5 = -900;
					girl_x6 = -450;
					girl_x7 = 650;
					girl_x8 = 900;
					girl_x9 = -200;
					up = 1000;
					right = -2100;
					sound9.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}

			//画面外に出ないようにする
			if (right < -2010){ right = -2010; }
			if (up < -1000)   { up = -1000; }
			if (right > 1700) { right = 1700; }
			if (up > 800)    { up = 800; }


			//"D"を押したときに右にリャマを移動させてかつ
			//リャマの画像を切り替える
			if (env.isPressKey('D')){
				i++;
				right += 10;
				if (10 > i)         {
					drawTextureBox(
						right, up,
						256, 256,
						95, 256,
						95, 120, image2);
				}
				if (i >= 10)        {
					drawTextureBox(
						right, up,
						256, 256,
						290, 256,
						95, 120, image2);
				}
				if (i > 20){ i = 0; }
			}

			//"W"を押したときにリャマの位置を上に移動させてかつ
			//画像を切り替える
			else if (env.isPressKey('W')){
				i++;
				up += 10;
				if (10 > i)         {
					drawTextureBox(
						right, up,
						256, 256,
						100, 400,
						95, 120, image2);
				}
				if (i >= 10)        {
					drawTextureBox(
						right, up,
						256, 256,
						290, 400,
						95, 120, image2);
				}
				if (i > 20){ i = 0; }
			}

			//"S"を押したときにリャマの位置を下に移動させてかつ
			//画像を切り替える
			else if (env.isPressKey('S')){
				i++;
				up -= 10;
				if (10 > i)         {
					drawTextureBox(
						right, up,
						256, 256,
						300, 0,
						95, 120, image2);
				}
				if (i >= 10)        {
					drawTextureBox(
						right, up,
						256, 256,
						110, 0,
						95, 120, image2);
				}
				if (i > 20){ i = 0; }
			}

			//"A"を押したときリャマの位置を左に移動させてかつ
			//画像を切り替える
			else if (env.isPressKey('A')){
				i++;
				right -= 10;
				if (10 > i)          {
					drawTextureBox(
						right, up,
						256, 256,
						95, 130,
						95, 120, image2);
				}
				if (i >= 10)         {
					drawTextureBox(
						right, up,
						256, 256,
						290, 130,
						95, 120, image2);
					if (i > 20){ i = 0; }
				}
			}

			//リャマの元画像
			else {
				drawTextureBox(right, up, 256, 256, 0, 256, 95, 120, image2);
			}

			//リャマのライフ情報
			font.size(50);
			font.draw("リャマの命", Vec2f(-650, 850), Color::white);
			if (fall == 0){
				drawTextureBox(-700, 900, 384, 128, 0, 0, 384, 128, image6);
			}
			if (fall == 1){
				drawTextureBox(-700, 900, 256, 128, 0, 0, 256, 128, image6);
			}
			if (fall == 2){
				drawTextureBox(-700, 900, 128, 128, 0, 0, 128, 128, image6);
			}

			//敵情報
			if (right > -2048 && up < -200){
				drawTextureBox(girl_x1, girl_y1, 256, 256, 0, 0, 256, 256, image7,
				Color(0,0.5,1),0,Vec2f(1,1),Vec2f(0,0));
				girl_y1 -= 20;
				int c;
				int v;
				c = right - girl_x1;
				v = up - girl_y1;
				if (girl_y1 < -1100){
					hit_fg = false;
				}
				if (c*c + v*v <= 100 * 100 && hit_fg == false){
					fall++;
					hit_fg = true;
					sound10.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;;
					}
				}
			}
			
			if (right > -1600 && up > 0){
				drawTextureBox(girl_x2, girl_y2, 256, 256, 0, 0, 256, 256, image10,Color(0, 0.5, 1), 0, Vec2f(1, 1), Vec2f(0, 0));
				girl_y2 += 19;
				int c;
				int v;
				c = right - girl_x2;
				v = up - girl_y2;
				if (girl_y2 > 1100){
					hit_fg = false;
				}
				if (c*c + v*v <= 100 * 100 && hit_fg == false){
					fall++;
					hit_fg = true;
					sound10.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}
			
			if (right > -1200 && up < 100){
				drawTextureBox(girl_x3, girl_y3, 256, 256, 0, 0, 256, 256, image7);
				girl_y3 -= 18;
				int c;
				int v;
				c = right - girl_x3;
				v = up - girl_y3;
				if (girl_y3 < -1100){
					hit_fg = false;
				}
				if (c*c + v*v <= 100 * 100 && hit_fg == false){
					fall++;
					hit_fg = true;
					sound10.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}
			
			if (right > -800 && up > -600){
				drawTextureBox(girl_x4, girl_y4, 256, 256, 0, 0, 256, 256, image10);
				girl_y4 += 18;
				int c;
				int v;
				c = right - girl_x4;
				v = up - girl_y4;
				if (girl_y4 < 1100){
					hit_fg = false;
				}
				if (c*c + v*v <= 100 * 100 && hit_fg == false){
					fall++;
					hit_fg = true;
					sound10.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}
			if (right > -670 && up > -100){
				drawTextureBox(girl_x5, girl_y5, 256, 256, 0, 0, 256, 256, image8);
				girl_x5 += 10;
				int c;
				int v;
				c = right - girl_x5;
				v = up - girl_y5;
				if (girl_x5 > 0){
					hit_fg = false;
					girl_y5 = 1300;
				}
				if (c*c + v*v <= 100 * 100 && hit_fg == false){
					fall++;
					hit_fg = true;
					sound10.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}
			if (right > -400 &&right<400&& up > 750){
				drawTextureBox(girl_x6, girl_y6, 256, 256, 0, 0, 256, 256, image8);
				girl_x6 += 10;
				int c;
				int v;
				c = right - girl_x6;
				v = up - girl_y6;
				if (girl_x6 > 400){
					hit_fg = false;
					girl_y6 = 1300;
				}
				if (c*c + v*v <= 100 * 100 && hit_fg == false){
					fall++;
					hit_fg = true;
					sound10.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}

			if (right > 600 && up<300 && up>-500){
				drawTextureBox(girl_x7, girl_y7, 256, 256, 0, 0, 256, 256, image10);
				girl_y7 += 7;
				int c;
				int v;
				c = right - girl_x7;
				v = up - girl_y7;
				if (girl_y7 > 100){
					hit_fg = false;
					girl_y7 = 1300;
				}
				if (c*c + v*v <= 100 * 100 && hit_fg == false){
					fall++;
					hit_fg = true;
					sound10.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}

			if (right < 900 && right>-100){
				if (up<-300 && up>-600){
					drawTextureBox(girl_x8, girl_y8, 256, 256, 0, 0, 256, 256, image9);
					girl_x8 -= 9;
					int c;
					int v;
					c = right - girl_x8;
					v = up - girl_y8;
					if (girl_x8 < -100){
						hit_fg = false;
						girl_y8 = 1300;
					}
					if (c*c + v*v <= 100 * 100 && hit_fg == false){
						fall++;
						hit_fg = true;
						sound10.play();
						if (fall == 4){
							up = 1000;
							right = -2100;
							girl_y1 = 1100;
							girl_y2 = -1300;
							girl_y3 = 1200;
							girl_y4 = -1300;
							girl_y5 = 0;
							girl_y6 = 800;
							girl_y7 = -500;
							girl_y8 = -400;
							girl_y9 = -1010;
							girl_y10 = -1300;
							girl_y11 = 1100;
							girl_x = 0;
							girl_x5 = -900;
							girl_x6 = -450;
							girl_x7 = 650;
							girl_x8 = 900;
							girl_x9 = -200;
							title = 1025;
							fall = 0;
							break;
						}
					}
				}
			}

			if (right > -100 && up < -870){
				drawTextureBox(girl_x9, girl_y9, 256, 256, 0, 0, 256, 256, image8);
				girl_x9 += 10;
				int c;
				int v;
				c = right - girl_x9;
				v = up - girl_y9;
				if (girl_x9 > 900){
					hit_fg = false;
					girl_y9 = 1300;
				}
				if (c*c + v*v <= 100 * 100 && hit_fg == false){
					fall++;
					hit_fg = true;
					sound10.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						girl_y10 = -1100;
						girl_y11 = 1100;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}
			if (right > 1500 && up>-1010&&up<800){
				drawTextureBox(girl_x10, girl_y10, 256, 256, 0, 0, 256, 256, image10);
				girl_y10 += 3;
				int c;
				int v;
				c = right - girl_x10;
				v = up - girl_y10;
				if (girl_y10 > 800){
					hit_fg = false;
				}
				if (girl_y10>-1000){
					girl_y10 += 15;
				}
				if (c*c + v*v <= 100 * 100 && hit_fg == false){
					fall++;
					hit_fg = true;
					sound10.play();
					if (fall == 4){
						up = 1000;
						right = -2100;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y9 = -1010;
						girl_y10 = -1300;
						girl_y11 = 1100;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_x7 = 650;
						girl_x8 = 900;
						girl_x9 = -200;
						title = 1025;
						fall = 0;
						break;
					}
				}
			}


			//ゴール
			if (right >= 1500){
				if (up >= 800){
					font.size(100);
					font.draw("ゴール！！", Vec2f(-500, 0), Color::yellow);
					font.draw("Rボタンを押してね！", Vec2f(-700, -200), Color::black);
					if (env.isPushKey('R')){
						right = -2100;
						up = 1000;
						girl_x = 0;
						girl_x5 = -900;
						girl_x6 = -450;
						girl_y1 = 1100;
						girl_y2 = -1300;
						girl_y3 = 1200;
						girl_y4 = -1300;
						girl_y5 = 0;
						girl_y6 = 800;
						girl_y7 = -500;
						girl_y8 = -400;
						girl_y10 = -1300;
						girl_y11 = 1100;
						title = 1025;
						fall = 0;
						sound7.play();
						sound8.stop();
						break;
					}
				}
			}

			env.end();
		}

	}
	env.end();
}
