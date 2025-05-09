#pragma once

class EnemyController : public Singleton<EnemyController>
{
private:
	const int ENEMY_SPAWN = 5;
	const int ENEMY_POOL_SIZE = 50;
	const float SPAWN_TIME = 1.0f;
	const float BOSS_SPAWN_TIME = 100.0f;
	const float ROUND_TIME = 10.0f;

public:
	EnemyController();
	~EnemyController();

	// 있어야 하는가 
	// 센터 때문에 있어야 하나
	// 센터에 사용할거면 벡터 다 넘기지 않고 랜덤으로 넘겨도 될거 같음
	const vector<Vector2>& GetSpawnPosition() { return _spawnPosition; }

	void Update();
	void Render(HDC hdc);
	void SetPlayer(Player* player);

private:
	void SetSpawnPosition();
	void Spawn();
	void BossSpawn();
	void RoundTimer();
	void SpawnTimer();

private:
	float _spawnTimer = 0.0f;
	float _bossSpawnTimer = 0.0f;
	float _roundTimer = 0.0f;
	bool _isSpawn = false;
	vector<Vector2> _spawnPosition;
	vector<Enemy*> _enemies;

};