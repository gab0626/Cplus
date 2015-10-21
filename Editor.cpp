#include "Editor.h"
#include "lib\framework.hpp"


void Editor::SetUp()
{
	for (int i = 0; i < 30; i++)
	{
		for (int k = 0; k < 50; k++)
		{
			Map[i][k] = 0;
		}
	}

	for (int i = 0; i < 30; i++)
	{
		for (int k = 0; k < 50; k++)
		{
			if (pos.y() >= 25 * k && pos.y() < 25 + (k + 1))
			{
				if (pos.x() <= 25 * -i && pos.x() > 25 * -(i + 1))
				{
					if (env.isPressButton(Mouse::LEFT))
					{
						Map[i][k] = 1;
					}
				}
			}
		}
	}

	
}

void Editor::Draw()
{

	for (int i = 0; i < 30; i++)
	{
		for (int k = 0; k < 50; k++)
		{
			switch (Map[i][k])
			{
			case 0:
				drawFillBox(25 * k, 25 * -i, 24, 24, Color::white);
				break;
			case 1:
				drawFillBox(25 * k, 25 * -i, 24, 24, Color::red);
				break;
			}
		}
	}

}