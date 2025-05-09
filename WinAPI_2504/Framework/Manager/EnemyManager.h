#pragma once

class EnemyManager : public Singleton<EnemyManager>
{
private:
	const int ENEMY_SPAWN = 5;
	const int ENEMY_POOL_SIZE = 50;
	const float SPAWN_TIME = 0.5f;
	const float BOSS_SPAWN_TIME = 50.0f;
	const float ROUND_TIME = 5.0f;

public:
	EnemyManager();
	~EnemyManager();

	// 있어야 하는가 
	// 센터 때문에 있어야 하나
	// 센터에 사용할거면 벡터 다 넘기지 않고 랜덤으로 넘겨도 될거 같음
	const vector<Vector2>& GetSpawnPosition() { return _spawnPosition; }

	void Update();
	void Render(HDC hdc);
	void SetPlayer(Player* player);

private:
	void SetSpawnPosition();
	void Spawn(int positionIndex);
	void BossSpawn();
	void RoundTimer();
	void SpawnTimer();

private:
	int _spawnCount = 0;
	int _positionIndex = 0;
	float _spawnTimer = 0.0f;
	float _bossSpawnTimer = 0.0f;
	float _roundTimer = 0.0f;
	bool _isSpawn = false;
	vector<Vector2> _spawnPosition;
	vector<Enemy*> _enemies;
};