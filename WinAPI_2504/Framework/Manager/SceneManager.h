#pragma once

enum SceneType
{
	Lobby,
	ChioceCharacter,
	InGame,
	EndGame,
	Max,
};

class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	Scene* GetScene() { return _scenes[(int)_sceneType]; }
	void SetSceneType(SceneType type) { _sceneType = type; }

private:
	void InitScene();

private:
	vector<Scene*> _scenes;
	SceneType _sceneType;
};