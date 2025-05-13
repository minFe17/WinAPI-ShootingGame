#include "Framework.h"

EnemyController::EnemyController()
{
	SetSpawnPosition();
	SetEnemyMap();
}

EnemyController::~EnemyController()
{
	for (int i = 0; i < (int)EEnemyType::Max; i++)
	{
		for (Enemy*& enemy : _enemies[(EEnemyType)i])
			delete enemy;
		_enemies[(EEnemyType)i].clear();
	}
	_enemies.clear();
}

void EnemyController::RoundTimer()
{
	if (!_isSpawn)
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

void EnemyController::SpawnTimer()
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

void EnemyController::SetEnemyMap()
{
	for (int j = 0; j < ENEMY_POOL_SIZE; j++)
		_enemies[EEnemyType::Dodger].push_back(new EnemyDodger());

	for (int j = 0; j < ENEMY_POOL_SIZE; j++)
		_enemies[EEnemyType::Grunt].push_back(new EnemyGrunt());

	for (int j = 0; j < ENEMY_POOL_SIZE; j++)
		_enemies[EEnemyType::Kamikaze].push_back(new EnemyKamikaze());
}

void EnemyController::Update()
{
	RoundTimer();
	SpawnTimer();

	/*for (int i = 0; i < _activeEnemies.size(); i++)
		_activeEnemies[i]->Update();*/

	for (int i = 0; i < (int)EEnemyType::Max; i++)
	{
		for (Enemy*& enemy : _enemies[(EEnemyType)i])
			enemy->Update();
	}
}

void EnemyController::Render(HDC hdc)
{
	/*for (int i = 0; i < _activeEnemies.size(); i++)
		_activeEnemies[i]->Render(hdc);*/

	for (int i = 0; i < (int)EEnemyType::Max; i++)
	{
		for (Enemy*& enemy : _enemies[(EEnemyType)i])
			enemy->Render(hdc);
	}
}

void EnemyController::SetPlayer(Player* player)
{
	/*for (int i = 0; i < _activeEnemies.size(); i++)
		_activeEnemies[i]->SetPlayer(player);*/
	for (int i = 0; i < (int)EEnemyType::Max; i++)
	{
		for (Enemy*& enemy : _enemies[(EEnemyType)i])
		{
			enemy->SetPlayer(player);
		}
	}
}

void EnemyController::SetSpawnPosition()
{
	for (int i = 1; i < 6; i++)
		_spawnPosition.push_back(Vector2(100 * i, 0));
}

void EnemyController::Spawn(int positionIndex)
{
	EEnemyType type = (EEnemyType)(rand() % (int)EEnemyType::Max);
	for (Enemy*& enemy : _enemies[type])
	{
		if (!enemy->IsActive())
		{
			enemy->Spawn(_spawnPosition[positionIndex]);
			_activeEnemies.push_back(enemy);
			break;
		}
	}
}

void EnemyController::BossSpawn()
{
	Vector2 bossPosition = { SCREEN_WIDTH / 2, 0 };
	_boss->Spawn(bossPosition);
}
