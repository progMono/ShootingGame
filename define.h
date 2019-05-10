#pragma once

#include<Windows.h>

#ifndef _DEFINE
#define _DEFINE

//-スクリーン設定-
#define SCREEN_WIDTH 640 //スクリーンの幅
#define SCREEN_HEIGHT 480 //スクリーンの高さ
//スクロールスピード
#define SCROLL_SPEED 2
#define HOSE_MOVE_SPEED 2
#define UI_WIDTH 100
#define UI_HEIGHT 75
#define MARGIN 5
//ホース
#define HOSE_MAX_NUM 3

//-プレイヤー設定-
//初期位置
#define PLAYER_INITX 296
#define PLAYER_INITY 400
//移動スピード
#define PLAYER_MOVE_SPEED 5
//弾の弾数とスピード
#define PSHOT_NUM 20
#define PSHOT_SPEED 8
//HP初期値
#define INIT_LIFE 3
//バッテリー初期値
#define INIT_BATTERY 100

//-敵の設定-
//数
#define ENEMY_NUM 5
//弾の数
#define ENEMY_SNUM 50

//-当たり判定設定-
//半径定義
#define PLAYER_COLLISION 6
#define ENEMY1_COLLISION 20

#define PSHOT_COLLISION 3
#define ESHOT0_COLLISION 10
#define ESHOT1_COLLISION 3
#define ESHOT2_COLLISION 2

#define MSG(m) {MessageBox(NULL,m,"メッセージ",MB_OK);}//メッセージボックス

//キー情報
extern char key[256];
//グローバルカウント
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
	bool flag;  //弾が発射中かどうか
	int x;      //x座標
	int y;      //y座標	
	int gh;     //グラフィックハンドル
	int width;  //画像の幅高さ
	int height; //画像の高さ
}Shot;

typedef struct _EnemyData
{
	int type;		//敵種類
	int s_type;		//弾種類
	int m_pattarn;	//移動パターン
	int s_pattarn;	//発射パターン
	int in_time;	//出現時間
	int stop_time;	//停止時間
	int shot_time;	//弾発射時間
	int out_time;	//帰還時間
	double x;			//x座標
	double y;			//y座標
	int speed;		//弾スピード
	int hp;			//HP
	int item;		//アイテム
}EnemyData;

typedef struct _E_Shot
{
	bool flag;  //弾が発射中かどうか
	double x;   //x座標
	double y;   //y座標
	double rad; //角度(ラジアン)
	int gh;     //グラフィックハンドル
	int width, height;  //画像の幅と高さ
	int pattern;//ショットパターン
	int speed;  //弾スピード
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