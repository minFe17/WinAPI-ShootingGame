#include "Framework.h"

ShootingScene::ShootingScene()
{
	BulletManager::Get();
	EnemyManager::Get()->SetPlayer(player);
	//EnemyController::Get()->SetPlayer(player);
	ItemManager::Get();
}

ShootingScene::~ShootingScene()
{
	delete player;
	BulletManager::Delete();
	EnemyManager::Delete();
	//EnemyController::Delete();
	ItemManager::Delete();
}

void ShootingScene::Update()
{
	player->Update();
	BulletManager::Get()->Update(player);
	EnemyManager::Get()->Update(player);
	//EnemyController::Get()->Update();
	ItemManager::Get()->Update();
	
}

void ShootingScene::Render(HDC hdc)
{
	EnemyManager::Get()->Render(hdc);
	//EnemyController::Get()->Render(hdc);
	BulletManager::Get()->Render(hdc);
	ItemManager::Get()->Render(hdc);
	player->Render(hdc);

	ShowScore(hdc);
}


void ShootingScene::ShowScore(HDC hdc)
{
	// 가운데 정렬
	SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
	SelectObject(hdc, _scoreFont);

	wstring score = to_wstring(ScoreManager::Get()->GetScore());
	TextOut(hdc, scorePosition.x, scorePosition.y, score.c_str(), score.length());
}

void ShootingScene::DrawPlayerIcon(HDC hdc)
{
	POINT front = { _playerIconCenter.x, _playerIconCenter.y - _playerIconRadius };
	POINT right = { _playerIconCenter.x + _playerIconRadius, _playerIconCenter.y + _playerIconRadius };
	POINT left = { _playerIconCenter.x - _playerIconRadius, _playerIconCenter.y + _playerIconRadius };

	MoveToEx(hdc, front.x, front.y, nullptr);
	LineTo(hdc, right.x, right.y);

	MoveToEx(hdc, front.x, front.y, nullptr);
	LineTo(hdc, left.x, left.y);

	MoveToEx(hdc, _playerIconCenter.x, _playerIconCenter.y + (_playerIconRadius >> 1), nullptr);
	LineTo(hdc, right.x, right.y);

	MoveToEx(hdc, _playerIconCenter.x, _playerIconCenter.y + (_playerIconRadius >> 1), nullptr);
	LineTo(hdc, left.x, left.y);
}
