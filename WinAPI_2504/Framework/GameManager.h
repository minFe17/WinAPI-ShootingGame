#pragma once

class GameManager : public Singleton<GameManager>
{
	friend class Singleton;
public:
	GameManager();
	~GameManager();

	void Update();
	void Render();
	void GameOver();
	void GameClear();

private:
	void Create();
	void Release();

private:
	HDC hdc;

	SceneManager* sceneManager;
	HDC backBufferDC;
	HBITMAP backBufferBitmap;
};