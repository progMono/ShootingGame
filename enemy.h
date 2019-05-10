#pragma once

#include"main.h"
#include"back.h"

#ifndef _ENEMY
#define _ENEMY

class ENEMY
{
private:
	//x,y���W
	double x, y;

	//�O���t�B�b�N�n���h��
	int gh;

	//�摜�T�C�Y
	int width, height;

	//  �o���C   ��~�C     �A�ҁC    ���˃^�C�~���O
	int in_time, stop_time, out_time, shot_time;

	//�G�̎��
	int type;
	//�e�̎��
	int s_type;
	//�ړ��p�^�[��
	int m_pattern;
	//�V���b�g�p�^�[��
	int s_pattern;

	//�G���o�����Ă���̃J�E���g
	int count;

	//���˂����e��
	int num;
	//���˒���̃��W�A��
	double rad;

	//�G���Ńt���O
	bool deadflag;
	//�G�N���X���Ńt���O
	bool endflag;

	//HP
	int hp;
	//�A�C�e��
	int item;

	//�e�\����
	E_Shot shot[ENEMY_SNUM];
	//�V���b�g�����Ă�悤�ɂȂ������̃t���O
	bool s_flag;
	//�V���b�g�����Ă�悤�ɂȂ��Ă���̃J�E���g
	int s_count;
private:
	BACK *back;
private:
	void Move();
	void Shot();
	void Draw();
	bool OutCheck();
public:
	//�G�̎��,�e�̎��,�ړ��p�^�[��,���˃p�^�[��,�o��,�A��,X���W,Y���W,�X�s�[�h,HP,�A�C�e��
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



