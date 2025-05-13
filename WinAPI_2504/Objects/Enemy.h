#pragma once

class Enemy : public PolygonVector
{
private:
	const int SPEED = 100;
	const int MAX_HP = 30;
	const float DAMAGE_INTERVAL = 0.1f;
	const float FIRE_INTERVAL = 1.0f;
	const int ITEM_DROP_RATE = 50; 
public:
	Enemy();
	~Enemy();

	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Move();
	virtual void Fire();
	virtual void Spawn(Vector2 pos);
	virtual void Damage(int damage);
	void SetPlayer(Player* player) { this->player = player; }



private:


private:
	float damageTimer = 0;
	float fireTimer = 0;
	bool isDamaged = false;


protected:
	int hp = 0;
	int damage = 0;
	HBRUSH hRedBrush;
	HBRUSH hBlueBrush;
	HBRUSH hSelectBrush;

	Player* player = nullptr;
};