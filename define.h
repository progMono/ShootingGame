#pragma once

#include<Windows.h>

#ifndef _DEFINE
#define _DEFINE

//-�X�N���[���ݒ�-
#define SCREEN_WIDTH 640 //�X�N���[���̕�
#define SCREEN_HEIGHT 480 //�X�N���[���̍���
//�X�N���[���X�s�[�h
#define SCROLL_SPEED 2
#define HOSE_MOVE_SPEED 2
#define UI_WIDTH 100
#define UI_HEIGHT 75
#define MARGIN 5
//�z�[�X
#define HOSE_MAX_NUM 3

//-�v���C���[�ݒ�-
//�����ʒu
#define PLAYER_INITX 296
#define PLAYER_INITY 400
//�ړ��X�s�[�h
#define PLAYER_MOVE_SPEED 5
//�e�̒e���ƃX�s�[�h
#define PSHOT_NUM 20
#define PSHOT_SPEED 8
//HP�����l
#define INIT_LIFE 3
//�o�b�e���[�����l
#define INIT_BATTERY 100

//-�G�̐ݒ�-
//��
#define ENEMY_NUM 5
//�e�̐�
#define ENEMY_SNUM 50

//-�����蔻��ݒ�-
//���a��`
#define PLAYER_COLLISION 6
#define ENEMY1_COLLISION 20

#define PSHOT_COLLISION 3
#define ESHOT0_COLLISION 10
#define ESHOT1_COLLISION 3
#define ESHOT2_COLLISION 2

#define MSG(m) {MessageBox(NULL,m,"���b�Z�[�W",MB_OK);}//���b�Z�[�W�{�b�N�X

//�L�[���
extern char key[256];
//�O���[�o���J�E���g
extern int g_count;

typedef struct _Chara
{
	int gh;
	double x;
	double y;
	int width;
	int height;
	int existflag;
	int count;
	bool moveflag;
}Chara;


typedef struct _Shot
{
	bool flag;  //�e�����˒����ǂ���
	int x;      //x���W
	int y;      //y���W	
	int gh;     //�O���t�B�b�N�n���h��
	int width;  //�摜�̕�����
	int height; //�摜�̍���
}Shot;

typedef struct _EnemyData
{
	int type;		//�G���
	int s_type;		//�e���
	int m_pattarn;	//�ړ��p�^�[��
	int s_pattarn;	//���˃p�^�[��
	int in_time;	//�o������
	int stop_time;	//��~����
	int shot_time;	//�e���ˎ���
	int out_time;	//�A�Ҏ���
	double x;			//x���W
	double y;			//y���W
	int speed;		//�e�X�s�[�h
	int hp;			//HP
	int item;		//�A�C�e��
}EnemyData;

typedef struct _E_Shot
{
	bool flag;  //�e�����˒����ǂ���
	double x;   //x���W
	double y;   //y���W
	double rad; //�p�x(���W�A��)
	int gh;     //�O���t�B�b�N�n���h��
	int width, height;  //�摜�̕��ƍ���
	int pattern;//�V���b�g�p�^�[��
	int speed;  //�e�X�s�[�h
}E_Shot;

typedef enum _Scene
{
	Title,
	Menu,
	Battle,
	Result,
	Clear,
	GameOver
}Scene;

#endif