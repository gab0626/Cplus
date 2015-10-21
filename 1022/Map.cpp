#include <fstream>
#include "Map.h"
#include "lib\framework.hpp"


void Map::SetUp()
{
	
	std::ifstream* Mapfile = nullptr;

	const char* NewStage = "res/Stage.txt";

	Mapfile = new std::ifstream(NewStage);

	for (int i = 0; i < 30; i++)
	{
		for (int k = 0; k < 30; k++)
		{
			*Mapfile >> Stage[i][k];
		}
	}
}

void Map::Draw()
{
	
	for (int i = 0; i < 30; i++)
	{
		for (int k = 0; k < 30; k++)
		{
			
			switch (Stage[i][k])
			{
			case 0:
				drawFillBox(25 * k, 25 * -i, 25, 25, Color::white);
				break;

			case 1:
				drawFillBox(25 * k, 25 * -i, 25, 25, Color::red);
				break;

			case 2:
				drawFillBox(25 * k, 25 * -i, 25, 25, Color::blue);
				break;

			}

		}

	}
	

}