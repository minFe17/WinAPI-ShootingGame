#pragma once

class EnemyManager : public Singleton<EnemyManager>
{
	friend class Singleton;
private:
	const int ENEMY_POOL_SIZE = 50;
	const float SPAWN_INTERVAL = 1.0f;
	const float BOSS_SPAWN = 5.0f;
private:
	EnemyManager();
	~EnemyManager();

public:
	void Update(Player* player);
	void Render(HDC hdc);

	void SpawnEnemy();

	void SpawnBossEnemy();

	void SetPlayer(Player* player);

	Enemy* GetClosestEnemy(Vector2 pos);
	const vector<Enemy*>& GetEnemies() { return enemies; }

private:
	vector<Enemy*> enemies;
	Enemy* enemyBoss;
	float spawnTimer = 0.0f;
	float runTime = 0.0f;

};