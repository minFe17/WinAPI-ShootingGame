#include "Framework.h"

EnemyBig::EnemyBig() : Enemy()
{
	hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	hSelectBrush = hBlueBrush;

	AddVertexs({ (float)-WIDTH/2,0 });
	AddVertexs({ 0,HEIGHT / 3 });
	AddVertexs({ (float)WIDTH/2,0 });
	AddVertexs({ 0,HEIGHT });
}

EnemyBig::~EnemyBig()
{
	DeleteObject(hRedBrush);
	DeleteObject(hBlueBrush);
}

void EnemyBig::Update()
{
	if (!isActive) return;

	Move();
//	Damage();	
	Fire();
}

void EnemyBig::Render(HDC hdc)
{
	if (!isActive) return;

	HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);

	DrawPolygon(hdc, vertexs);
	SelectObject(hdc, defaultBrush);
}

void EnemyBig::Spawn(Vector2 pos)
{
	center = pos;
	isActive = true;
	hSelectBrush = hBlueBrush;
	hp = MAX_HP;
	damage = DAMAGE;
	radius = RADIUS;
}

void EnemyBig::Move()
{
	center.y += SPEED * DELTA;

	if (center.y > SCREEN_HEIGHT)
	{
		isActive = false;
	}
}

void EnemyBig::Fire()
{
	fireTimer += DELTA;

	if (fireTimer >= FIRE_INTERVAL)
	{
		fireTimer = 0.0f;

		Vector2 direction = player->GetCenter() - center;
		BulletManager::Get()->Fire(center, "Enemy",damage,COLOR_ENEMY_BULLET, direction);
	}
}
