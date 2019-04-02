#pragma once

#include"main.h"
#include"define.h"
#include"control.h"

class SCENE
{
private:
	CONTROL *control;
	Scene scene;

private:
	void SceneChange(Scene *scene);
	void SceneTitle(Scene *scene);
	void SceneMenu(Scene *scene);
	void SceneBattle(Scene *scene);
	void SceneResult(Scene *scene);
	void SceneClear(Scene *scene);
	void SceneGameOver(Scene *scene);
public:
	SCENE();
	void All();
	~SCENE();
};

