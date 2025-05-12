#pragma once
class Player;

class Enemy : public Circle
{
private:
	const int SPEED = 300;	
	const int MAX_HP = 60;
	const float DAMAGE_INTERVAL = 0.1f;
	const float FIRE_INTERVAL = 1.0f;

public:
	Enemy();
	~Enemy();

	void Update();
	void Render(HDC hdc);

	void Spawn(Vector2 pos);
	void SetPlayer(Player* player) { this->player = player; }
	void Damage(int damage);

private:
	void Move();
	void Fire();
	void ColorEffect();

private:
	int hp = 0;
	float damageTimer = 0;
	float fireTimer = 0;
	bool isDamaged = false;	

	HBRUSH hRedBrush;
	HBRUSH hBlueBrush;
	HBRUSH hSelectBrush;	

	Player* player = nullptr;
};