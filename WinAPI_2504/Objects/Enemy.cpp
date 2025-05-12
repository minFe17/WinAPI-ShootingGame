#include "Framework.h"

Enemy::Enemy()
{
	hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));

	hSelectBrush = hBlueBrush;
}

Enemy::~Enemy()
{
	DeleteObject(hRedBrush);
	DeleteObject(hBlueBrush);
}

void Enemy::Update()
{
	if (!isActive) return;

	Move();
//	Damage();
	Fire();
}

void Enemy::Render(HDC hdc)
{
	if (!isActive) return;

	HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);

	Circle::Render(hdc);

	SelectObject(hdc, defaultBrush);
}

void Enemy::Spawn(Vector2 pos)
{
	center = pos;
	isActive = true;
	hSelectBrush = hBlueBrush;
	hp = MAX_HP;
	isDamaged = false;
}

void Enemy::Damage(int damage)
{
	/*
	if (isDamaged)
	{
		damageTimer += DELTA;

		if (damageTimer >= DAMAGE_INTERVAL)
		{
			damageTimer = 0;
			isDamaged = false;
			hSelectBrush = hBlueBrush;
		}
		//return;
	}

	if (BulletManager::Get()->GetCollidedBullet(this, "Player") != nullptr)
	{
		//isActive = false;
		hp -= damage;
		isDamaged = true;
		hSelectBrush = hRedBrush;

		if (hp <= 0)
		{
			isActive = false;
		}
	}

	*/
	hp -= damage;
	isDamaged = true;
	hSelectBrush = hRedBrush;

	if (hp <= 0)
	{
		isActive = false;
	}

}

void Enemy::Move()
{
	center.y += SPEED * DELTA;

	if (center.y > SCREEN_HEIGHT)
	{
		isActive = false;
	}
}

void Enemy::Fire()
{
	fireTimer += DELTA;

	if (fireTimer >= FIRE_INTERVAL)
	{
		fireTimer = 0.0f;

		Vector2 direction = player->GetCenter() - center;
		BulletManager::Get()->Fire(center, "Enemy",damage, COLOR_ENEMY_BULLET, direction);
	}
}
