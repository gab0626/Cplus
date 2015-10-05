#include "graffic.h"


void graffic(Vec2f pos, Vec2f size, Texture text, Vec2f pick, Vec2f drawsize)
{
	drawTextureBox(pos.x(), pos.y(), size.x(), size.y(), pick.x(), pick.y(), drawsize.x(), drawsize.y(), text);
}