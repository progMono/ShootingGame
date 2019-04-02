#include "enemy.h"



ENEMY::ENEMY(int type, int s_type, int m_pattern, int s_pattern,
	int in_time, int stop_time, int shot_time, int out_time,
	double x, double y, int speed, int hp, int item)
{
	back = new BACK;

	int temp;
	int w, h;

	//サイズ
	width = 25;
	height = 25;

	//敵の種類
	this->type = type;

	//弾の種類
	this->s_type = s_type;

	//移動パターンとショットパターン
	this->m_pattern = m_pattern;
	this->s_pattern = s_pattern;

	//座標セット
	this->x = x;
	this->y = y;
	adPosition();

	//出現，停止，発射，帰還時間セット
	this->in_time = in_time;
	this->stop_time = stop_time;
	this->shot_time = shot_time;
	this->out_time = out_time;

	//hpとアイテムに代入
	this->hp = hp;
	this->item = item;

	//敵画像読み込み
	if (type == 0)
	{
		LoadDivGraph("image/Enemy/Figure/enemy_Eye.png", 3, 1, 3, 25, 25, &gh);
	}

	//弾画像読み込み
	switch (s_type)
	{
	case 0:
		temp = LoadGraph("image/Enemy/Bullet/enemy_bullet.png");
		break;
	case 1:
		temp = LoadGraph("image/Enemy/Bullet/enemy_bullet2.png");
		break;
	case 2:
		temp = LoadGraph("image/Enemy/Bullet/enemy_bullet3.png");
		break;
	}

	GetGraphSize(temp, &w, &h);

	//弾の初期化
	for (int i = 0; i < ENEMY_SNUM; ++i)
	{
		shot[i].flag = false;
		shot[i].gh = temp;
		shot[i].width = w;
		shot[i].height = h;
		shot[i].pattern = s_pattern;
		shot[i].speed = speed;
		shot[i].x = x;
		shot[i].y = y;
	}

	count = 0;
	s_count = 0;
	num = 0;
	rad = 0;

	deadflag = false;
	endflag = false;
	s_flag = false;
}

void ENEMY::adPosition()
{
	//座標セット
	//this->x -= width / 2;
	//this->y -= height / 2;
}

void ENEMY::Move()
{
	if (!deadflag)
	{
		switch (m_pattern)
		{
		case 0:
			if (in_time == g_count)
			{
				back->GetHosePosition(rand() % HOSE_MAX_NUM, &x, &y);
				adPosition();
			}			
			if (in_time < g_count && g_count < stop_time) { y += 2; }
			else if (out_time < g_count) { y -= 2; }
			break;
		default:
			break;
		}
		//画面からはみ出したら、deaflag(はみ出すか死ぬかのフラグ)を true にする
		if (g_count >= stop_time)
		{
			if (OutCheck()) { deadflag = true; }
		}
		++count;
	}
}

bool ENEMY::OutCheck()
{
	if (x < -50 || x > SCREEN_WIDTH - width / 2 || y < -50 || y > SCREEN_HEIGHT - height / 2) { return true; }
	else { return false; }
}

void ENEMY::Draw()
{
	if (in_time < g_count)
	{
		if (!deadflag)
		{
			DrawGraph(x, y, gh, TRUE);
		}
	}	
}

bool ENEMY::All()
{
	Draw();

	Move();

	return endflag;
}

ENEMY::~ENEMY()
{

}
