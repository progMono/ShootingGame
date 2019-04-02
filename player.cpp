#include "player.h"


/*
* �v���C���[�N���X�̃R���X�g���N�^
*/
PLAYER::PLAYER()
{
	int tmp;
	int w, h;

	if (-1 == LoadDivGraph("image/Player/Figure/mainmachine13.png", 3, 3, 1, 34, 41, gh))
	{
		MSG("�G���[����");
	}

	width = 34;
	height = 41;

	x = 296;
	y = 400;

	xcount = 0, ycount = 0;

	ix = 0, iy = 0, result = 0;

	dcount = 0;

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
* �v���C���[�̈ړ�
*/
void PLAYER::Move()
{
	if (CheckHitKey(KEY_INPUT_LEFT) == 1) { x -= PLAYER_MOVE_SPEED; }
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1) { x += PLAYER_MOVE_SPEED; }
	if (CheckHitKey(KEY_INPUT_UP) == 1) { y -= PLAYER_MOVE_SPEED; }
	if (CheckHitKey(KEY_INPUT_DOWN) == 1) { y += PLAYER_MOVE_SPEED; }

	ix = 60; //��� x=n*ix ����
	if ((int)x % ix >= 0 && (int)x % ix < ix / 3) { result = 0; }
	if ((int)x % ix >= ix / 3 && (int)x % ix < ix * 2 / 3) { result = 1; }
	if ((int)x % ix >= ix * 2 / 3 && (int)x % ix < ix) { result = 2; }

	Save();
}

/*
* �v���C���[�̈ړ��͈�
*/
void PLAYER::Save()
{
	if (x < width / 2 + MARGIN) { x = width / 2 + MARGIN; }
	if (x > SCREEN_WIDTH - width / 2 - MARGIN) { x = SCREEN_WIDTH - width / 2 - MARGIN; }
	if (y < height / 2 + 160) { y = height / 2 + 160; }
	if (y > SCREEN_HEIGHT - height / 2 - MARGIN) { y = SCREEN_HEIGHT - height / 2 - MARGIN; }
}

/*
* �v���C���[�̕`��
*/
void PLAYER::Draw()
{
	//�e�`��
	for (int i = 0; i < PSHOT_NUM; ++i)
	{
		if (shot[i].flag)
		{
			DrawGraph(shot[i].x - shot[i].width / 2,
				shot[i].y - shot[i].height / 2, shot[i].gh, TRUE);
		}
	}

	//�����Ă���Ε`��
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
			//���W�������l�ɖ߂�
			x = PLAYER_INITX;
			y = PLAYER_INITY;
			//
		}
	}
	else
	{
		//�ʏ�`��
		DrawGraph(x - width / 2, y - height / 2, gh[result], TRUE);
	}
}

/*
* �v���C���[�̒e
*/
void PLAYER::Shot()
{
	if (!damageflag)
	{
		//�L�[��������ĂāC���C6���[�v�Ɉ�񔭎�
		if (CheckHitKey(KEY_INPUT_Z) == 1 && count % 6 == 0)
		{
			for (int i = 0; i < PSHOT_NUM; ++i)
			{
				if (shot[i].flag == false)
				{
					shot[i].flag = true;
					shot[i].x = x;
					shot[i].y = y;
					break;
				}
			}
		}
	}

	//�e���ړ������鏈��
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
* �v���C���[�̍��W�擾
*
* param *x : ������� x ���W�|�C���^
* param *y : ������� y ���W�|�C���^
*/
void PLAYER::GetPosition(double *x, double *y)
{
	*x = this->x;
	*y = this->y;
}

/*
* �v���C���[�̒e�̍��W�擾
*
* param index : �e�̔z��ԍ�
* param *x : ������� x ���W�|�C���^
* param *y : ������� y ���W�|�C���^
* return : �e�����݂��Ă���Ȃ� true, ���Ă��Ȃ��Ȃ� false
*/
bool PLAYER::GetShotPosition(int index, double *x, double *y)
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

/*
* PLAYER �N���X�̊Ǘ��֐�
*/
void PLAYER::All()
{
	//���ł��ĂȂ��Ƃ��������s
	if (!damageflag)
	{
		Move();
	}
	Shot();
	Draw();

	++count;
}

PLAYER::~PLAYER()
{
	
}
