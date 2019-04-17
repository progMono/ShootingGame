#include "UI.h"


UI::UI()
{
	this->life = INIT_LIFE;
	this->battery = INIT_BATTERY;

	width = 100;
	height = 300;
	LoadDivGraph("image/UI/battery3.png", 10, 10, 1, width, height, batteryGh);

	this->x = 0;
	this->y = SCREEN_HEIGHT - height - UI_HEIGHT;
}

void UI::setUI(double life, double battery)
{
	this->life = life;
	this->battery = battery;
}

void UI::Draw()
{
	if (battery > 90) {
		result = 0;
	}
	else if (battery > 80) {
		result = 1;
	}
	else if (battery > 70) {
		result = 2;
	}
	else if (battery > 60) {
		result = 3;
	}
	else if (battery > 50) {
		result = 4;
	}
	else if (battery > 40) {
		result = 5;
	}
	else if (battery > 30) {
		result = 6;
	}
	else if (battery > 20) {
		result = 7;
	}
	else if (battery > 10) {
		result = 8;
	}
	else if (battery > 0) {
		result = 9;
	}
	
	DrawGraph(x, y, batteryGh[result],TRUE);
}

void UI::All()
{
	Draw();
}

UI::~UI()
{
}
