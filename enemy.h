#pragma once

#include"main.h"
#include"back.h"

#ifndef _ENEMY
#define _ENEMY

class ENEMY
{
private:
	//x,y座標
	double x, y;

	//グラフィックハンドル
	int gh;

	//画像サイズ
	int width, height;

	//  出現，   停止，     帰還，    発射タイミング
	int in_time, stop_time, out_time, shot_time;

	//敵の種類
	int type;
	//弾の種類
	int s_type;
	//移動パターン
	int m_pattern;
	//ショットパターン
	int s_pattern;

	//敵が出現してからのカウント
	int count;

	//発射した弾数
	int num;
	//発射直後のラジアン
	double rad;

	//敵消滅フラグ
	bool deadflag;
	//敵クラス消滅フラグ
	bool endflag;

	//HP
	int hp;
	//アイテム
	int item;

	//弾構造体
	E_Shot shot[ENEMY_SNUM];
	//ショットが撃てるようになったかのフラグ
	bool s_flag;
	//ショットが撃てるようになってからのカウント
	int s_count;
private:
	BACK *back;
private:
	void Move();
	void Shot();
	void Draw();
	bool OutCheck();
public:
	//敵の種類,弾の種類,移動パターン,発射パターン,出現,帰還,X座標,Y座標,スピード,HP,アイテム
	ENEMY(int type, int s_type, int m_pattern, int s_pattern,
		int in_time, int stop_time, int shot_time, int out_time,
		double x, double y, int speed, int hp, int item);
	~ENEMY();
	void getPosition(double *x, double *y);
	void setShotFlag();
	bool getDeadFlag();
	void setDeadFlag();
	bool All();
};
#endif // !



