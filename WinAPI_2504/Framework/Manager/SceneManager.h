#pragma once

enum class ESceneType
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
	void SetSceneType(ESceneType type) { _sceneType = type; }
	void InitInGamePlayer(Player* player);

private:
	void InitScene();

private:
	vector<Scene*> _scenes;
	ESceneType _sceneType;
};