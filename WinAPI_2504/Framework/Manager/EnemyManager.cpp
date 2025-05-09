#include "Framework.h"

EnemyManager::EnemyManager()
{
	SetSpawnPosition();

	_enemies.resize(ENEMY_POOL_SIZE);
	for (Enemy*& enemy : _enemies)
	{
		enemy = new Enemy();
		enemy->SetActive(false);
	}
}

EnemyManager::~EnemyManager()
{
	for (Enemy*& enemy : _enemies)
	{
		delete enemy;
	}
	_enemies.clear();
}

void EnemyManager::RoundTimer()
{
	if(!_isSpawn)
		_roundTimer += DELTA;
	_bossSpawnTimer += DELTA;

	if (!_isSpawn && _roundTimer >= ROUND_TIME)
	{
		_isSpawn = true;
		_roundTimer = 0.0f;
	}

	if (_bossSpawnTimer >= BOSS_SPAWN_TIME)
		BossSpawn();
}

void EnemyManager::SpawnTimer()
{
	int positionIndex = rand() % _spawnPosition.size();

	if (!_isSpawn)
		return;

	_spawnTimer += DELTA;

	if (_spawnTimer >= SPAWN_TIME)
	{
		_spawnTimer = 0.0f;
		_spawnCount++;
		Spawn(positionIndex);
		
		if (_spawnCount == ENEMY_SPAWN)
		{
			_spawnCount = 0;
			_isSpawn = false;

		}
	}
}

void EnemyManager::Update()
{
	RoundTimer();
	SpawnTimer();

	for (Enemy*& enemy : _enemies)
		enemy->Update();
}

void EnemyManager::Render(HDC hdc)
{
	for (Enemy*& enemy : _enemies)
		enemy->Render(hdc);
}

void EnemyManager::SetPlayer(Player* player)
{
	for (Enemy*& enemy : _enemies)
		enemy->SetPlayer(player);
}

void EnemyManager::SetSpawnPosition()
{
	for (int i = 1; i < 6; i++)
		_spawnPosition.push_back(Vector2(100 * i, 0));
}

void EnemyManager::Spawn(int positionIndex)
{
	for (Enemy*& enemy : _enemies)
	{
		if (!enemy->IsActive())
		{
			enemy->Spawn(_spawnPosition[positionIndex]);
			break;
		}
	}
}

void EnemyManager::BossSpawn()
{
	Vector2 bossPosition = {SCREEN_WIDTH / 2, 0};
	// 보스 스폰 구현 필요
}
