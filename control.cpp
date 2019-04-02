#include "control.h"


/*
* CONTROL �N���X�̃R���X�g���N�^
*/
CONTROL::CONTROL()
{
	player = new PLAYER;

	back = new BACK;

	double tempEx =0, tempEy=0;

	for (int i = 0; i < ENEMY_NUM; ++i)
	{
		//GetHosePosition(rand() % HOSE_MAX_NUM, &tempEx, &tempEy);
		enemy[i] = new ENEMY(0, 1, 0, 1, 100, 250, 1, 500, tempEx, tempEy, 1, 1, 1);
	}
}

/*
* CONTROL �N���X�̊Ǘ��֐�
*/
void CONTROL::All()
{
	//�`��̈���w��
	SetDrawArea(MARGIN, MARGIN, 640 - MARGIN, 480 - MARGIN);

	back->All();

	player->All();

	for (int i = 0; i < ENEMY_NUM; ++i)
	{
		if (enemy[i] != NULL)
		{
			if (enemy[i]->All())
			{
				delete enemy[i];
				enemy[i] = NULL;
			}
		}
	}

	++g_count;
}

/*
* �~�̓����蔻��
*
* param c1 : �~1�̔��a
* param c2 : �~2�̔��a
* param cx1 : �~1�� x ���W
* param cx2 : �~2�� x ���W
* param cy1 : �~1�� y ���W
* param cy2 : �~2�� y ���W
* return : ������Ȃ� true, �Ⴄ�Ȃ� false
*/
bool CONTROL::CircleCollision(double c1, double c2, double cx1, double cx2, double cy1, double cy2)
{
	double hlength = c1 + c2;
	double xlength = cx1 - cx2;
	double ylength = cy1 - cy2;

	if (hlength*hlength >= xlength * xlength + ylength * ylength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CONTROL::SquareCollision(double x1, double y1, double x2, double y2)
{
	return true;
}

/*
* �v���C���[�ƓG�Ƃ̓����蔻��
*/
void CONTROL::CollisionAll()
{
	//�v���C���[�ƓG�� x, y ���W
	double px, py, ex, ey;
	//
	bool tempflag = false;

	//����L�����̒e�ƓG�̓����蔻��
	for (int i = 0; i < PSHOT_NUM; ++i)
	{
		if (player->GetShotPosition(i, &px, &py))
		{
			for (int s = 0; s < ENEMY_NUM; ++s)
			{ //�G�N���X�̃|�C���^��NULL����Ȃ��A����deadflag��false(����łȂ����A�҂��ĂȂ�)
				/*if (enemy[s] != NULL && !enemy[s]->GetDeadFlag())
				{
					enemy[s]->GetPosition(&ex, &ey);
					//�����蔻��
					if (CircleCollision(PSHOT_COLLISION, ENEMY1_COLLISION, px, ex, py, ey))
					{
						//�������Ă���΁Cdeadflag �𗧂Ă�
						enemy[s]->SetDeadFlag();
						//���������e�̃t���O��߂�
						player->SetShotFlag(i, false);

					}
				}*/
			}
		}
	}
}

/*
* �R���g���[���̃f�X�g���N�^
*/
CONTROL::~CONTROL()
{
	delete player;
	delete back;

	for (int i = 0; i < ENEMY_NUM; ++i)
	{
		if (enemy[i] != NULL)
		{
			if (enemy[i]->All())
			{
				delete enemy[i];
				enemy[i] = NULL;
			}
		}
	}
}