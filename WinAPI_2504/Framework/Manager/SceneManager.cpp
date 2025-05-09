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
	// �� ���鶧���� �߰� (enumŸ�Կ� �´� �� �����)
	_scenes.push_back(new LobbyScene());
	_scenes.push_back(new ShootingScene());
}
