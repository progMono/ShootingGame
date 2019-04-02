#include "control.h"


/*
* CONTROL クラスのコンストラクタ
*/
CONTROL::CONTROL()
{
	player = new PLAYER;

	back = new BACK;

	double tempEx =0, tempEy=0;

	for (int i = 0; i < ENEMY_NUM; ++i)
	{
		//GetHosePosition(rand() % HOSE_MAX_NUM, &tempEx, &tempEy);
		enemy[i] = new ENEMY(0, 1, 0, 1, 100, 250, 1, 500, tempEx, tempEy, 1, 1, 1);
	}
}

/*
* CONTROL クラスの管理関数
*/
void CONTROL::All()
{
	//描画領域を指定
	SetDrawArea(MARGIN, MARGIN, 640 - MARGIN, 480 - MARGIN);

	back->All();

	player->All();

	for (int i = 0; i < ENEMY_NUM; ++i)
	{
		if (enemy[i] != NULL)
		{
			if (enemy[i]->All())
			{
				delete enemy[i];
				enemy[i] = NULL;
			}
		}
	}

	++g_count;
}

/*
* 円の当たり判定
*
* param c1 : 円1の半径
* param c2 : 円2の半径
* param cx1 : 円1の x 座標
* param cx2 : 円2の x 座標
* param cy1 : 円1の y 座標
* param cy2 : 円2の y 座標
* return : 当たりなら true, 違うなら false
*/
bool CONTROL::CircleCollision(double c1, double c2, double cx1, double cx2, double cy1, double cy2)
{
	double hlength = c1 + c2;
	double xlength = cx1 - cx2;
	double ylength = cy1 - cy2;

	if (hlength*hlength >= xlength * xlength + ylength * ylength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CONTROL::SquareCollision(double x1, double y1, double x2, double y2)
{
	return true;
}

/*
* プレイヤーと敵との当たり判定
*/
void CONTROL::CollisionAll()
{
	//プレイヤーと敵の x, y 座標
	double px, py, ex, ey;
	//
	bool tempflag = false;

	//操作キャラの弾と敵の当たり判定
	for (int i = 0; i < PSHOT_NUM; ++i)
	{
		if (player->GetShotPosition(i, &px, &py))
		{
			for (int s = 0; s < ENEMY_NUM; ++s)
			{ //敵クラスのポインタがNULLじゃない、かつdeadflagがfalse(死んでない＆帰還してない)
				/*if (enemy[s] != NULL && !enemy[s]->GetDeadFlag())
				{
					enemy[s]->GetPosition(&ex, &ey);
					//当たり判定
					if (CircleCollision(PSHOT_COLLISION, ENEMY1_COLLISION, px, ex, py, ey))
					{
						//当たっていれば，deadflag を立てる
						enemy[s]->SetDeadFlag();
						//当たった弾のフラグを戻す
						player->SetShotFlag(i, false);

					}
				}*/
			}
		}
	}
}

/*
* コントロールのデストラクタ
*/
CONTROL::~CONTROL()
{
	delete player;
	delete back;

	for (int i = 0; i < ENEMY_NUM; ++i)
	{
		if (enemy[i] != NULL)
		{
			if (enemy[i]->All())
			{
				delete enemy[i];
				enemy[i] = NULL;
			}
		}
	}
}