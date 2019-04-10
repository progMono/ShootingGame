#include "player.h"


/*
* プレイヤークラスのコンストラクタ
*/
PLAYER::PLAYER()
{
	int tmp;
	int w, h;

	if (-1 == LoadDivGraph("image/Player/Figure/mainmachine13.png", 3, 3, 1, 34, 41, gh))
	{
		MSG("エラー発生");
	}

	width = 34;
	height = 41;

	x = 396 - width / 2;
	y = 300 + height / 2;

	xcount = 0, ycount = 0;

	ix = 0, iy = 0, result = 0;

	dcount = 0;

	battery = INIT_BATTERY;

	existFlag = true;
	damageflag = false;

	memset(shot, 0, sizeof(shot));

	tmp = LoadGraph("image/Player/Bullet/bullet.png");

	GetGraphSize(tmp, &w, &h);

	for (int i = 0; i < PSHOT_NUM; i++)
	{
		shot[i].flag = false;
		shot[i].gh = tmp;
		shot[i].width = w;
		shot[i].height = h;
	}

	count = 0;
}

/*
* プレイヤーの移動
*/
void PLAYER::Move()
{
	if (CheckHitKey(KEY_INPUT_LEFT) == 1) { x -= PLAYER_MOVE_SPEED; }
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1) { x += PLAYER_MOVE_SPEED; }
	if (CheckHitKey(KEY_INPUT_UP) == 1) { y -= PLAYER_MOVE_SPEED; }
	if (CheckHitKey(KEY_INPUT_DOWN) == 1) { y += PLAYER_MOVE_SPEED; }

	ix = 60; //画面 x=n*ix ごと
	if ((int)x % ix >= 0 && (int)x % ix < ix / 3) { result = 0; }
	if ((int)x % ix >= ix / 3 && (int)x % ix < ix * 2 / 3) { result = 1; }
	if ((int)x % ix >= ix * 2 / 3 && (int)x % ix < ix) { result = 2; }

	Save();
}

/*
* プレイヤーの移動範囲
*/
void PLAYER::Save()
{
	if (x < width / 2 + UI_WIDTH) { x = width / 2 + UI_WIDTH; }
	if (x > SCREEN_WIDTH - width / 2 - MARGIN) { x = SCREEN_WIDTH - width / 2 - MARGIN; }
	if (y < height / 2 + 80) { y = height / 2 + 80; }
	if (y > SCREEN_HEIGHT - height / 2 - UI_HEIGHT) { y = SCREEN_HEIGHT - height / 2 - UI_HEIGHT; }
}

/*
* プレイヤーの描画
*/
void PLAYER::Draw()
{
	//弾描画
	for (int i = 0; i < PSHOT_NUM; ++i)
	{
		if (shot[i].flag)
		{
			DrawGraph(shot[i].x - shot[i].width / 2,
				shot[i].y - shot[i].height / 2, shot[i].gh, TRUE);
		}
	}

	//生きていれば描画
	if (damageflag)
	{
		if (dcount > 20)
		{
			if (dcount % 2 == 0)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 140);
				DrawGraph(PLAYER_INITX - width / 2, PLAYER_INITY - height / 2 + 60 - (dcount - 20), gh[1], TRUE);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			else
			{
				DrawGraph(PLAYER_INITX - width / 2, PLAYER_INITY - height / 2 + 60 - (dcount - 20), gh[1], TRUE);
			}
		}
		++dcount;
		if (dcount == 80)
		{
			damageflag = false;
			dcount = 0;
			//座標を初期値に戻す
			x = PLAYER_INITX;
			y = PLAYER_INITY;
			//
		}
	}
	else
	{
		//通常描画
		DrawGraph(x - width / 2, y - height / 2, gh[result], TRUE);
	}
}

/*
* プレイヤーの弾
*/
void PLAYER::Shot()
{
	if (!damageflag)
	{
		//キーが押されてて，かつ，6ループに一回発射
		if (CheckHitKey(KEY_INPUT_Z) == 1 && count % 6 == 0)
		{
			for (int i = 0; i < PSHOT_NUM; ++i)
			{
				if (shot[i].flag == false)
				{
					shot[i].flag = true;
					shot[i].x = x;
					shot[i].y = y;
					disBattery(0.5);
					break;
				}
			}
		}
	}

	//弾を移動させる処理
	for (int i = 0; i < PSHOT_NUM; ++i)
	{
		if (shot[i].flag)
		{
			shot[i].y -= PSHOT_SPEED;
			if (shot[i].y < -10) { shot[i].flag = false; }
		}
	}
}

/*
* プレイヤーの座標取得
*
* param *x : 代入する x 座標ポインタ
* param *y : 代入する y 座標ポインタ
*/
void PLAYER::getPosition(double *x, double *y)
{
	*x = this->x;
	*y = this->y;
}

void PLAYER::disBattery(double value)
{
	if (battery > 0)
		battery -= value;
	if (battery < 0)
		battery = 0;
}

/*
* プレイヤーの弾の座標取得
*
* param index : 弾の配列番号
* param *x : 代入する x 座標ポインタ
* param *y : 代入する y 座標ポインタ
* return : 弾が存在しているなら true, していないなら false
*/
bool PLAYER::getShotPosition(int index, double *x, double *y)
{
	if (shot[index].flag)
	{
		*x = shot[index].x;
		*y = shot[index].y;
		return true;
	}
	else
	{
		return false;
	}
}

void PLAYER::setShotFlag(int index, bool flag)
{
	shot[index].flag = flag;
}

/*
* PLAYER クラスの管理関数
*/
void PLAYER::All()
{
	//消滅してないときだけ実行
	if (!damageflag)
	{
		Move();
	}
	disBattery(0.5);
	Shot();
	Draw();

	++count;
}

PLAYER::~PLAYER()
{
	
}
