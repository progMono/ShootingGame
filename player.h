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
	double move_speed;
	//横方向と縦方向のカウント数
	int xcount, ycount;
	//添え字用変数
	int ix, iy, result;
	int mpix;

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

	int s_power;
	//カウント
	int count;
	int chargecount;

	double battery;

	Chara charger;

	bool chargeflag;
public:
	//int mpix;
	//double battery;
private:
	void Move();
	void Save();
	void Draw();
	void Shot();
	void Fix();
public:
	PLAYER();
	void getPosition(double *x, double *y);
	double getLife();
	double getBattery();
	void changeBattery(double value);
	bool getShotPosition(int index, double *x, double *y);
	void setShotFlag(int index, bool flag);
	void setBatteryPower();
	/*
	void SetDamageFlag();
	bool GetDamageFlag();
	*/
	void All();
	~PLAYER();
};

