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

void SceneManager::InitInGamePlayer(Player* player)
{
	ShootingScene* inGameScene = (ShootingScene*)_scenes[(int)SceneType::InGame];
	inGameScene->SetPlayer(player);
}

void SceneManager::InitScene()
{
	_scenes.push_back(new LobbyScene());
	_scenes.push_back(new ChoiceCharacterScene());
	_scenes.push_back(new ShootingScene());
}
