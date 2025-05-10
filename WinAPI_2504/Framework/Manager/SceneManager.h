#pragma once

enum class SceneType
{
	Lobby,
	ChoiceCharacter,
	InGame,
	GameOver,
	GameClear,
	Max,
};

class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	Scene* GetScene() { return _scenes[(int)_sceneType]; }
	void SetSceneType(SceneType type) { _sceneType = type; }
	void InitInGamePlayer(Player* player);

private:
	void InitScene();

private:
	vector<Scene*> _scenes;
	SceneType _sceneType;
};