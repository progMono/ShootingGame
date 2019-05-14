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

	GetGraphSize(*gh, &width, &height);

	x = 396 - width / 2;
	y = 300 + height / 2;

	xcount = 0, ycount = 0;

	ix = 0, iy = 0, result = 0;

	dcount = 0;

	move_speed = PLAYER_MOVE_SPEED;
	
	battery = INIT_BATTERY;

	mpix = 0;

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

	s_power = 6;

	count = 0;

	charger.gh = LoadGraph("image/Player/UI/charger.png");

	GetGraphSize(charger.gh, &charger.width, &charger.height);

	charger.x = SCREEN_WIDTH / 2;
	charger.y = SCREEN_HEIGHT - UI_HEIGHT - charger.height;

	chargecount = 0;
}

/*
* プレイヤーの移動
*/
void PLAYER::Move()
{
	batteryflag = false;
	if (CheckHitKey(KEY_INPUT_LEFT) == 1) { x -= move_speed; batteryflag = true; mpix++; }
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1) { x += move_speed; batteryflag = true; mpix++; }
	if (CheckHitKey(KEY_INPUT_UP) == 1) { y -= move_speed; batteryflag = true; mpix++; }
	if (CheckHitKey(KEY_INPUT_DOWN) == 1) { y += move_speed; batteryflag = true; mpix++; }

	ix = 60; //画面 x=n*ix ごと
	if ((int)x % ix >= 0 && (int)x % ix < ix / 3) { result = 0; }
	if ((int)x % ix >= ix / 3 && (int)x % ix < ix * 2 / 3) { result = 1; }
	if ((int)x % ix >= ix * 2 / 3 && (int)x % ix < ix) { result = 2; }

	if (mpix > 50)
	{
		changeBattery(-5);
		mpix = 0;
	}

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

	if ((x > charger.x + charger.width / 4) && (x < charger.x + charger.width * 3 / 4) && (y > charger.y)) 
	{
		//チャージャーの中心
		x = charger.x + charger.width / 2;
		batteryflag = true;
		chargeflag = true; 
	}
	else
	{
		chargeflag = false;
	}
}

/*
* プレイヤーの描画
*/
void PLAYER::Draw()
{
	//バッテリーの描画
	DrawGraph(charger.x, charger.y, charger.gh, TRUE);

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
	if (!damageflag && !chargeflag)
	{
		//キーが押されてて，かつ，6ループに一回発射
		if (CheckHitKey(KEY_INPUT_Z) == 1 && count % s_power == 0)
		{
			for (int i = 0; i < PSHOT_NUM; ++i)
			{
				if (shot[i].flag == false)
				{
					shot[i].flag = true;
					shot[i].x = x;
					shot[i].y = y;
					batteryflag = true;
					changeBattery(-0.5);
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

void PLAYER::Fix()
{
	if (chargeflag && chargecount>=50)
	{
		changeBattery(5);
		mpix = 0;
		chargecount = 0; 
	}
	
	chargecount++;
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

double PLAYER::getLife()
{
	return life;
}

double PLAYER::getBattery()
{
	return battery;
}

void PLAYER::changeBattery(double value)
{
	if (batteryflag)
	{
		if (battery >= 0 && battery <= 100)
			battery += value;
		if (battery >= 100)
			battery = 100;
		if (battery <= 0)
			battery = 0;
	}
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

void PLAYER::setBatteryPower()
{
	if (battery > 90) {
		move_speed = PLAYER_MOVE_SPEED;
		s_power = 6;
	}
	else if (battery > 80) {
		move_speed = PLAYER_MOVE_SPEED * 9 / 10;
	}
	else if (battery > 70) {
		move_speed = PLAYER_MOVE_SPEED * 8 / 10;
		s_power = 10;
	}
	else if (battery > 60) {
		move_speed = PLAYER_MOVE_SPEED * 7 / 10;
	}
	else if (battery > 50) {
		move_speed = PLAYER_MOVE_SPEED * 6 / 10;
		s_power = 14;
	}
	else if (battery > 40) {
		move_speed = PLAYER_MOVE_SPEED * 5 / 10;
	}
	else if (battery > 30) {
		move_speed = PLAYER_MOVE_SPEED * 4 / 10;
		s_power = 18;
	}
	else if (battery > 20) {
		move_speed = PLAYER_MOVE_SPEED * 3 / 10;
	}
	else if (battery > 10) {
		move_speed = PLAYER_MOVE_SPEED * 2 / 10;
		s_power = 22;
	}
	else if (battery > 0) {
		move_speed = PLAYER_MOVE_SPEED * 1.1 / 10;
	}
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
	setBatteryPower();
	Fix();
	Shot();
	Draw();

	++count;
}

PLAYER::~PLAYER()
{
	
}
