#include "Framework.h"

SceneManager::SceneManager()
{
	InitScene();
}

SceneManager::~SceneManager()
{
	for (int i = 0; i < _scenes.size(); i++)
		delete _scenes[i];
	_scenes.clear();
}

void SceneManager::InitScene()
{
	// 씬 만들때마다 추가 (enum타입에 맞는 씬 만들기)
	_scenes.push_back(new LobbyScene());
	_scenes.push_back(new ShootingScene());
}
