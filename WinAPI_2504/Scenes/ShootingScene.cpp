#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{
	player = new Player();	

	BulletManager::Get();
	EnemyController::Get()->SetPlayer(player);
}

ShootingScene::~ShootingScene()
{
	delete player;

	BulletManager::Delete();
	EnemyController::Delete();
}

void ShootingScene::Update()
{
	player->Update();

	BulletManager::Get()->Update();
	EnemyController::Get()->Update();
}

void ShootingScene::Render(HDC hdc)
{
	player->Render(hdc);

	BulletManager::Get()->Render(hdc);
	EnemyController::Get()->Render(hdc);
}
