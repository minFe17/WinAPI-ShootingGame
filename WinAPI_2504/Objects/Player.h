#pragma once

#include "Bullet.h"
class Item;
class Player : public PolygonVector
{
protected:
	const int SPEED = 300;
	const int BULLET_POOL_SIZE = 50;
	const float AIM_LENGTH = 50.0f;
	const float PLAYER_POWERUP_PERCENT = 0.2f;
	const float EFFECT_TIME = 0.3f;
	const int INIT_BULLET_COUNT = 1;
	const int MAX_BULLET_COUNT = 5;


public:
	Player();
	~Player();

	virtual void Update();	
	void Render(HDC hdc);

	void LevelUp(ItemType type);

	void CollisionItem();

	void Damage();

	void HitEnemy();
	bool IsDead() const { return isDead; }

protected:
	void BulletCount();
	virtual void Fire();
	void ControlFire();
	void ControlMove();
	void ClampToScreenBounds();

	void UpdatePen();
	void ColorEffect();
	void DrawShieldEffect(HDC hdc);
	void DrawLine(HDC hdc);
	COLORREF GetColor();

protected:
	int damage;
	int baseDamage;
	int bulletCount = INIT_BULLET_COUNT;
	bool isShield = false;
	bool isDead = false;
	bool isDamaged = false;
	float damageTimer = 0.0f;
	float fireCooldown;
	float fireTimer = 0.0f;

	Vector2 firePos = {};
	vector<Vector2> firePosList;
	HPEN hPen;
	COLORREF baseColor;

	HPEN shieldPen;
	HBRUSH nullBrush;
};