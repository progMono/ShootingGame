#include"main.h"
#include"scene.h"

//キー取得用配列
char key[256];
//グローバルカウント
int g_count;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();

	SCENE *scene = new SCENE;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0)
	{
		scene->All();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { break; }
	}

	WaitKey();
	DxLib_End();
}