#include "UI.h"



UI::UI()
{
	width = 100;
	height = 300;
	LoadDivGraph("image/UI/battery.png", 10, 10, 1, width, height, batteryGh);

	this->x = MARGIN;
	this->y = SCREEN_HEIGHT - height - MARGIN;
}

void UI::Draw()
{
	DrawGraph(x, y, batteryGh[0],TRUE);
}

void UI::All()
{
	Draw();
}

UI::~UI()
{
}
