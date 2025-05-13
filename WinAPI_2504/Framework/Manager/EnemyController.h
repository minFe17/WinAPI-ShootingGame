#pragma once
#include <map>

enum class EEnemyType
{
	Kamikaze,
	Grunt,
	Dodger,
	Max,
};

class EnemyController : public Singleton<EnemyController>
{
private:
	const int ENEMY_SPAWN = 5;
	const int ENEMY_POOL_SIZE = 50;
	const float SPAWN_TIME = 0.5f;
	const float BOSS_SPAWN_TIME = 180.0f;
	const float ROUND_TIME = 5.0f;

public:
	EnemyController();
	~EnemyController();

	void Update();
	void Render(HDC hdc);
	void SetPlayer(Player* player);

private:
	void SetSpawnPosition();
	void Spawn(int positionIndex);
	void BossSpawn();
	void RoundTimer();
	void SpawnTimer();
	void SetEnemyMap();


private:
	int _spawnCount = 0;
	int _positionIndex = 0;
	float _spawnTimer = 0.0f;
	float _bossSpawnTimer = 0.0f;
	float _roundTimer = 0.0f;
	bool _isSpawn = false;

	vector<Vector2> _spawnPosition;
	map<EEnemyType, vector<Enemy*>> _enemies;

	// 죽으면 죽은 몬스터 삭제 필요
	vector<Enemy*> _activeEnemies;




	Enemy* _boss;
};