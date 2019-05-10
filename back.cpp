#include "back.h"



BACK::BACK()
{
	gh = LoadGraph("image/Back/back_factory.png");

	x = 0;
	y = -UI_HEIGHT;

	for (int i = 0; i < HOSE_MAX_NUM; i++)
	{
		hose[i].gh = LoadGraph("image/Back/hose_2.png");

		GetGraphSize(hose[i].gh, &hose[i].width, &hose[i].height);

		hose[i].x = (SCREEN_WIDTH - hose[i].width) * (i + 1) / HOSE_MAX_NUM - hose[i].width;
		hose[i].y = 35;

		hose[i].count = 0;
		hose[i].moveflag = true;
	}
} 

/**

*/
void BACK::Draw()
{
	DrawGraph(x, y, gh, FALSE);
	for (int i = 0; i < HOSE_MAX_NUM; i++)
	{
		//DrawGraph(hose[i].x, hose[i].y, hose[i].Handle, TRUE);
	}
}

/**

*/
void BACK::Move()
{
	for (int i = 0; i < HOSE_MAX_NUM; i++)
	{
		if (hose[i].x > MARGIN && hose[i].moveflag) { hose[i].x -= HOSE_MOVE_SPEED; }
		else if (hose[i].x <= MARGIN && hose[i].count < 10)
		{
			hose[i].count++;
			if (hose[i].count == 10) { hose[i].moveflag = false; }
		}
		else if (hose[i].x < (SCREEN_WIDTH - hose[i].width - MARGIN) && !hose[i].moveflag) 
		{
			hose[i].x += HOSE_MOVE_SPEED;
		}
		else
		{
			hose[i].count--;
			if (hose[i].count == 0) { hose[i].moveflag = true; }
		}
		printfDx("hose[%d]x = %f\n", i, hose[i].x);
	}
}

/**
* 特定のホースのゲッター
* 
* param index : 配列番号
* param *x : x 座標のポインタ
* param *y : y 座標のポインタ
*/
void BACK::GetHosePosition(int index, double *x,double *y)
{
	*x = this->hose[index].x + this->hose[index].width / 2;
	*y = this->hose[index].y + 60;
}

/**

*/
void BACK::All()
{
	Draw();

	//Move();
}

BACK::~BACK()
{

}