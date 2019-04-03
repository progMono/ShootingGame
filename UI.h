#pragma once

#include "main.h"

class UI
{
private:
	int x, y;

	int batteryGh[10];

	int width, height;
private:
	void Draw();
public:
	UI();
	~UI();
	void All();
};

