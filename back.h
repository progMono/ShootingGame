#pragma once

#include"main.h"

class BACK
{
private:
	int gh;

	double x, y;

	Chara hose[HOSE_MAX_NUM];
private:
	void Draw();
public:
	BACK();
	~BACK();
	void GetHosePosition(int index, double *x, double *y);
	void Move();
	void All();
};

