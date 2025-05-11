#include "Framework.h"

ShootingScene::ShootingScene()
{
;	BulletManager::Get();
}

ShootingScene::~ShootingScene()
{
	delete player;

	BulletManager::Delete();
	EnemyManager::Delete();
}

void ShootingScene::Update()
{
	player->Update();

	BulletManager::Get()->Update();
	EnemyManager::Get()->Update();
}

void ShootingScene::Render(HDC hdc)
{
	player->Render(hdc);

	BulletManager::Get()->Render(hdc);
	EnemyManager::Get()->Render(hdc);

	ShowScore(hdc);
	ShowHP(hdc);
}

void ShootingScene::ShowScore(HDC hdc)
{
	// 가운데 정렬
	SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
	SelectObject(hdc, _scoreFont);

	wstring score = to_wstring(ScoreManager::Get()->GetScore());
	TextOut(hdc, scorePosition.x, scorePosition.y, score.c_str(), score.length());
}

void ShootingScene::ShowHP(HDC hdc)
{
	DrawPlayerIcon(hdc);

	SetTextAlign(hdc, TA_LEFT | TA_TOP);
	// 점수가 아닌 플레이어 체력
	//wstring hp = to_wstring(ScoreManager::Get()->GetScore());
	//TextOut(hdc, 70, 5, hp.c_str(), hp.length());
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
