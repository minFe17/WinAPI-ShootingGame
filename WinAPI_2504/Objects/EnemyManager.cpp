#include "Framework.h"

EnemyManager::EnemyManager()
{
	enemies.resize(ENEMY_POOL_SIZE);
	for (Enemy*& enemy : enemies)
	{
		enemy = new Enemy();
		enemy->SetActive(false);
	}
}

EnemyManager::~EnemyManager()
{
	for (Enemy*& enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();
}

void EnemyManager::Update(Player* player)
{
	spawnTimer += DELTA;

	if (spawnTimer >= SPAWN_INTERVAL)
	{
		spawnTimer = 0.0f;
		SpawnEnemy();
	}

	for (Enemy*& enemy : enemies)
	{
		enemy->Update();

		if (!enemy->IsActive()) continue;

		if (enemy->IsCollisionCircle(player))
		{
			player->HitEnemy();
			enemy->SetActive(false);
		}
	}
}

void EnemyManager::Render(HDC hdc)
{
	for (Enemy*& enemy : enemies)
	{
		enemy->Render(hdc);
	}
}

void EnemyManager::SpawnEnemy()
{
	int randomX = rand() % SCREEN_WIDTH;

	for (Enemy*& enemy : enemies)
	{
		if (!enemy->IsActive())
		{
			enemy->Spawn({(float)randomX, 0 });
			break;
		}
	}
}

void EnemyManager::SetPlayer(Player* player)
{
	for (Enemy*& enemy : enemies)
	{
		enemy->SetPlayer(player);
	}
}


Enemy* EnemyManager::GetClosestEnemy(Vector2 pos)
{
	Enemy* closest = nullptr;
	float minDist = FLT_MAX;

	for (Enemy* enemy : enemies)
	{
		if (!enemy->IsActive()) continue;

		Vector2 enemyPos = enemy->GetCenter();

		if (enemyPos.y > pos.y) continue;
		float dist = (enemyPos - pos).SqrMagnitude();

		if (dist < minDist)
		{
			minDist = dist;
			closest = enemy;
		}
	}

	return closest;
}
