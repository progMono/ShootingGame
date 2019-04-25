#pragma once

#include "main.h"

class UI
{
private:
	int x, y;

	int batteryGh[10];

	double battery;

	double life;

	int result;

	int width, height;
private:
	void Draw();
public:
	UI();
	~UI();
	void setUI(double life, double battery);
	void All();
};

