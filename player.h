#pragma once

#include"main.h"

class PLAYER
{
private:
	//x���W,y���W
	double x, y;
	//�摜��
	int width, height;
	//�O���t�B�b�N�n���h��
	int gh[3];
	//�ړ��W��
	float move;
	//�������Əc�����̃J�E���g��
	int xcount, ycount;
	//�Y�����p�ϐ�
	int ix, iy, result;

	//�v���C���[�̃��C�t
	int life;
	
	bool damageflag;
	bool endflag;
	//�_���[�W���̃J�E���g
	int dcount;

	//�����Ă��邩�̃t���O
	bool existFlag;
	//�e
	Shot shot[PSHOT_NUM];
	//�J�E���g
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

