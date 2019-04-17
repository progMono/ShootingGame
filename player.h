#pragma once

#include"main.h"

class PLAYER
{
private:
	//x座標,y座標
	double x, y;
	//画像幅
	int width, height;
	//グラフィックハンドル
	int gh[3];
	//移動係数
	float move;
	//横方向と縦方向のカウント数
	int xcount, ycount;
	//添え字用変数
	int ix, iy, result,mpix;

	//プレイヤーのライフ
	int life;
	
	bool damageflag;
	bool endflag;
	bool batteryflag;
	//ダメージ中のカウント
	int dcount;

	//生きているかのフラグ
	bool existFlag;
	//弾
	Shot shot[PSHOT_NUM];
	//カウント
	int count;
public:
	double battery;
private:
	void Move();
	void Save();
	void Draw();
	void Shot();
public:
	PLAYER();
	void getPosition(double *x, double *y);
	double getLife();
	double getBattery();
	void disBattery(double value);
	bool getShotPosition(int index, double *x, double *y);
	void setShotFlag(int index, bool flag);
	/*
	void SetDamageFlag();
	bool GetDamageFlag();
	*/
	void All();
	~PLAYER();
};

