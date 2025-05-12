#include "Framework.h"

#include "Scenes/ShootingScene.h"

GameManager::GameManager()
{
	hdc = GetDC(hWnd);

	backBufferDC = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBufferDC, backBufferBitmap);

	sceneManager = SceneManager::Get();
	Create();
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);

	Release();

	DeleteObject(backBufferBitmap);
	DeleteDC(backBufferDC);
}

void GameManager::Update()
{
	Timer::Get()->Update();
	Input::Get()->Update();

	sceneManager->GetScene()->Update();

	InvalidateRect(hWnd, nullptr, false);
}

void GameManager::Render()
{
	PatBlt(backBufferDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);

	sceneManager->GetScene()->Render(backBufferDC);

	BitBlt(hdc,
		0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
		backBufferDC, 0, 0, SRCCOPY);
}

void GameManager::GameOver()
{
	SceneManager::Get()->SetSceneType(ESceneType::GameOver);
}

void GameManager::GameClear()
{
	SceneManager::Get()->SetSceneType(ESceneType::GameClear);
}

void GameManager::Create()
{
	Timer::Get();
	Input::Get();
	ScoreManager::Get();
}

void GameManager::Release()
{
	Timer::Delete();
	Input::Delete();
}
