#include "scene.h"


SCENE::SCENE()
{
	scene = Title;

	control = &CONTROL::GetInstance();
}

void SCENE::SceneChange(Scene *scene)
{
	switch (*scene)
	{
	case Title:
		SceneTitle(scene);
		break;
	case Menu:
		SceneMenu(scene);
		break;
	case Battle:
		SceneBattle(scene);
		break;
	case Result:
		SceneResult(scene);
	case Clear:
		SceneClear(scene);
		break;
	case GameOver:
		SceneGameOver(scene);
		break;
	default:
		break;
	}
}

void SCENE::SceneTitle(Scene *scene)
{
	DrawFormatString(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 3 / 4, GetColor(255, 255, 255), "-- PLEASE INPUT ENTER KEY --");
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		*scene = Menu;
	}
}

void SCENE::SceneMenu(Scene *scene)
{
	DrawFormatString(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 3 / 4, GetColor(255, 255, 255), "-- THIS IS MENU --");
	DrawFormatString(SCREEN_WIDTH / 2, SCREEN_HEIGHT * 3 / 4 + 20, GetColor(255, 255, 255), "-- INPUT S KEY --> BATTLE START --");
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		*scene = Battle;
	}
}

void SCENE::SceneBattle(Scene *scene)
{
	control->All();
}

void SCENE::SceneResult(Scene *scene)
{

}

void SCENE::SceneClear(Scene *scene)
{

}

void SCENE::SceneGameOver(Scene *scene)
{

}

void SCENE::All()
{
	SceneChange(&scene);
}

SCENE::~SCENE()
{
}
