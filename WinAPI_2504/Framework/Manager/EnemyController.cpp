#include "Framework.h"

EnemyController::EnemyController()
{
	SetSpawnPosition();

	_enemies.resize(ENEMY_POOL_SIZE);
	for (Enemy*& enemy : _enemies)
	{
		enemy = new Enemy();
		enemy->SetActive(false);
	}
}

EnemyController::~EnemyController()
{
	for (Enemy*& enemy : _enemies)
	{
		delete enemy;
	}
	_enemies.clear();
}

void EnemyController::RoundTimer()
{
	_roundTimer += DELTA;
	_bossSpawnTimer += DELTA;

	if (_roundTimer >= ROUND_TIME)
		_isSpawn = true;

	if (_bossSpawnTimer >= BOSS_SPAWN_TIME)
		BossSpawn();
}

void EnemyController::SpawnTimer()
{
	if (!_isSpawn)
		return;

	for (int i = 0; i < ENEMY_SPAWN; i++)
	{
		_spawnTimer += DELTA;
		if (_spawnTimer >= SPAWN_TIME)
		{
			_spawnTimer = 0.0f;
			Spawn();
		}
	}
	_isSpawn = false;
}

void EnemyController::Update()
{
	RoundTimer();
	SpawnTimer();

	for (Enemy*& enemy : _enemies)
	{
		enemy->Update();
	}
}

void EnemyController::Render(HDC hdc)
{
	for (Enemy*& enemy : _enemies)
	{
		enemy->Render(hdc);
	}
}

void EnemyController::SetPlayer(Player* player)
{
	for (Enemy*& enemy : _enemies)
	{
		enemy->SetPlayer(player);
	}
}

void EnemyController::SetSpawnPosition()
{
	for (int i = 1; i < 6; i++)
	{
		_spawnPosition.push_back(Vector2(100 * i, 0));
	}
}

void EnemyController::Spawn()
{
	int positionIndex = rand() % _spawnPosition.size();

	for (Enemy*& enemy : _enemies)
	{
		if (!enemy->IsActive())
		{
			enemy->Spawn(_spawnPosition[positionIndex]);
			break;
		}
	}
}

void EnemyController::BossSpawn()
{
	Vector2 bossPosition = {SCREEN_WIDTH / 2, 0};
}
