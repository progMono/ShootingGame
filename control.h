#pragma once

#ifndef DEF_CONTROL
#define DEF_CONTROL

#include"main.h"
#include"player.h"
#include"back.h"
#include"enemy.h"
#include"UI.h"

class CONTROL
{
private:
	//�v���C���[�N���X
	PLAYER *player;

	//�w�i�N���X
	BACK *back;

	//�G�N���X
	ENEMY *enemy[ENEMY_NUM];

	//UI�N���X
	UI *ui;
private:
	double ex, ey;
	Chara hose[HOSE_MAX_NUM];
private:
	CONTROL();
public:
	~CONTROL();
	bool CircleCollision(double c1, double c2, double cx1, double cx2, double cy1, double cy2);
	bool SquareCollision(double x1, double y1, double x2, double y2);
	double getBattery();
	//void GetHosePosition(int index, double *x, double *y);
	void CollisionAll();
	void All();
	static CONTROL& GetInstance()
	{
		static CONTROL control;
		return control;
	}
};

#endif //
