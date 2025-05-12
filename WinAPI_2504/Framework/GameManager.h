#pragma once

class GameManager
{
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