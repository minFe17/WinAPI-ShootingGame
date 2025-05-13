#pragma once

class EnemyBig : public Enemy
{
private:
	const int SPEED = 50;
	const int MAX_HP = 100;
	const int RADIUS = 1;
	const int DAMAGE = 10;
	const float FIRE_INTERVAL = 3.0f;
	const float WIDTH = 200;
	const float HEIGHT = 50;


public:
	EnemyBig();
	~EnemyBig();

	void Update();
	void Render(HDC hdc);

	void Spawn(Vector2 pos);

	void SetPlayer(Player* player) { this->player = player; }

private:
	void Move();
	void Fire();

private:
	float fireTimer = 0;
};