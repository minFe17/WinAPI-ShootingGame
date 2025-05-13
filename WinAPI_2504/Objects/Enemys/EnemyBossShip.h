#pragma once

class Player;  // Player 클래스 전방 선언

class ShipTurret : Enemy {
private:
	const float BARREL_SIZE = 30;
	const int DAMAGE = 10;
	float angle = 0;
	bool isActive = false;
	Player* player;
	Vector2 Direction;
	HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH hSelectBrush = hBlueBrush;
	Vector2 center = {};
	vector<Vector2> barrel = {
	{ 0.0f, 4.0f },
	{ BARREL_SIZE * 1.0f, 4.0f },
	{ BARREL_SIZE * 1.0f, -4.0f },
	{ 0.0f, -4.0f }
	};
public:

	ShipTurret() { radius = 30; };
	void SetPlayer(Player* player) { this->player = player; }
	void SetCenter(Vector2 center) { this->center = center; }
	void Render(HDC hdc) {
		if (!isActive) return;
		HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);
		Circle::Render(hdc);
		DrawRotatedRectangle(hdc, barrel, angle);
		SelectObject(hdc, defaultBrush);
	}
	void spawn(Vector2 pos) {
		isActive = true;
		SetCenter(pos);
	}
	void Update() {

	}

};

class EnemyBossShip : public Enemy
{
private:
	const int SPEED = 30;
	const int MAX_HP = 300;
	const int RADIUS = 50;
	const int DAMAGE = 10;
	const float DAMAGE_INTERVAL = 0.1f;
	const float FIRE_INTERVAL = 2.0f;
	const float BULLET_SPEED = 200;
	const float TURRET_RADIUS = 15;  // 포대의 반지름
	const float TURRET_SPACING = 40; // 포대 간의 간격
	const float TURRET_HP = 30; // 포대 간의 간격
	const float BARREL_SIZE = 30;
	vector<Vector2> barrel = {
		{ 0.0f, 4.0f },
		{ BARREL_SIZE * 1.0f, 4.0f },
		{ BARREL_SIZE * 1.0f, -4.0f },
		{ 0.0f, -4.0f }
	};
	struct Turret {
		Vector2 position;
		Vector2 direction;
		bool isActive;
		int hp;
		const int MAX_TURRET_HP = 50;
	};

public:
	EnemyBossShip();
	~EnemyBossShip();

	void Update();
	void Render(HDC hdc);
	void Spawn(Vector2 pos);
	void SetPlayer(Player* player) { this->player = player; }
	void SetIsDead(bool isDead) { this->isDead = isDead; }
	bool IsDead() { return isDead; }
private:
	void Damage();
	void Move();
	void Fire();
	void InitializeTurrets();
	void DrawTurrets(HDC hdc);
	bool IsTurretHit(const Vector2& bulletPos);

private:
	int hp = 0;
	float damageTimer = 0;
	float fireTimer = 0;
	float spawnTimer = 0.0f;  // 스폰 타이머 추가
	bool isDamaged = false;
	bool isDead = false;
	HBRUSH hRedBrush;
	HBRUSH hBlueBrush;
	HBRUSH hSelectBrush;
	HBRUSH hTurretBrush;

	vector<Turret> turrets;  // 6개의 포대
};

