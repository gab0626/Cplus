#include "class.h"

void title::upDate()
{


}

void title::draw()
{

	drawFillBox(0, 0, 500, 500, Color::white);

}

SceneName title::Shift()
{
	return Game;
}

void game::upDate()
{

	

}

void game::draw()
{

	drawFillBox(0, 0, 500, 500, Color::blue);

}

SceneName game::Shift()
{
	return Result;
}

void result::upDate()
{


}

void result::draw()
{

	drawFillBox(0, 0, 500, 500, Color::red);

}

SceneName result::Shift()
{
	return Title;
}

