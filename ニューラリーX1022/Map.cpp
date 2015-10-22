#include <fstream>
#include "Map.h"
#include "lib\framework.hpp"
#include "MapSlide.h"

Map::Map()

{
	StageChip = Texture("res/Stagechip.png");
};



void Map::SetUp()
{
	
	std::ifstream* Mapfile = nullptr;

	const char* NewStage = "res/Stage.txt";

	Mapfile = new std::ifstream(NewStage);

	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		for (int k = 0; k < MAX_WIDTH; k++)
		{
			*Mapfile >> Stage[i][k];
		}
	}
}



void Map::Draw()
{

	if (MapMoveLeft == true)
	{
		pos.x() -= 5;
	}

	for (int i = 0; i < MAX_HEIGHT; i++)
	{
		for (int k = 0; k < MAX_WIDTH; k++)
		{
			Vec2f Mpos = Vec2f(BLOCK_SIZE * k, BLOCK_SIZE * -i) - pos;

			switch (Stage[i][k])
			{
			case 0:
				drawTextureBox(Mpos.x(), Mpos.y(), BLOCK_SIZE, BLOCK_SIZE, 0, 0, 45, 30, StageChip);
				break;

			case 1:
				drawTextureBox(Mpos.x(), Mpos.y(), BLOCK_SIZE, BLOCK_SIZE, 170, 760, 40, 30, StageChip);
				break;

			case 2:
				drawFillBox(Mpos.x(), Mpos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::blue);
				break;

			case 3:
				drawFillBox(Mpos.x(), Mpos.y(), BLOCK_SIZE, BLOCK_SIZE, Color::maroon);
				break;

			
			}

		}

	}
	

}