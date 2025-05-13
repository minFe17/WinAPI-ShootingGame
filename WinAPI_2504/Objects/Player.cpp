#include "Framework.h"

Player::Player()
{
	fireTimer = 0.0f;
	fireCooldown = 0.0f;
	hPen = CreatePen(PS_SOLID, 5, RGB(100, 230, 150));
	baseDamage = 10;
	damage = baseDamage;
	center = { SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 4 / 5 };
	radius = 15;

	shieldPen = CreatePen(PS_SOLID, 3, RGB(0, 255, 255));
	nullBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
}

Player::~Player()
{
	DeleteObject(hPen);	
	DeleteObject(shieldPen);
}

void Player::Update()
{
	fireTimer += DELTA;
	ControlMove();	
	ControlFire();
	CollisionItem();
	Damage();
	ClampToScreenBounds();
	ColorEffect();
}

void Player::Render(HDC hdc)
{
	UpdatePen();           
	DrawLine(hdc);         
	DrawShieldEffect(hdc); 
}

void Player::LevelUp(ItemType type)
{
	switch (type) {
	case ItemType::MultiShot:
		if (bulletCount < MAX_BULLET_COUNT)
			bulletCount++;
		break;
	case ItemType::PowerUp:
		damage +=baseDamage*PLAYER_POWERUP_PERCENT;
		break;
	case ItemType::Shield:
		if (!isShield)
			isShield = true;
		break;
	}
}

void Player::CollisionItem()
{

	Item* item = ItemManager::Get()->GetCollidedPlayer(this);
	if (item != nullptr)
	{
		LevelUp(item->GetType());
	}
}

void Player::Damage()
{
	Bullet* bullet = BulletManager::Get()->GetCollidedBullet(this, "Enemy");
	if (bullet != nullptr) HitEnemy();
}
void Player::HitEnemy()
{
	if (isShield)
	{
		isShield = false;
		return;
	}

	if (bulletCount > INIT_BULLET_COUNT || damage > baseDamage)
	{
		bulletCount = INIT_BULLET_COUNT;
		damage = baseDamage;
		return;
	}

	GameManager::Get()->GameOver();
	isDead = true;
	isDamaged = true;
	damageTimer = 0.0f;
}


void Player::BulletCount()
{
	firePosList.clear();

	int count = min(bulletCount, MAX_BULLET_COUNT);
	float spacing = 20.0f;
	float startX = firePos.x - spacing * (count - 1) / 2.0f;

	for (int i = 0; i < count; ++i)
	{
		firePosList.push_back(Vector2(startX + i * spacing, firePos.y));
	}
}

void Player::Fire()
{
	BulletCount();

	for (Vector2 pos : firePosList) {
		BulletManager::Get()->Fire(pos, "Player", damage,GetColor());
	}
}

void Player::ControlFire()
{
	if (Input::Get()->IsKeyDown(VK_SPACE) && fireTimer >= fireCooldown)
	{
		Fire();
		fireTimer = 0.0f;
	}

}

void Player::ControlMove()
{
	if (GetAsyncKeyState('D'))
		center += Vector2::Right() * SPEED * DELTA;
	if (GetAsyncKeyState('A'))
		center += Vector2::Left() * SPEED * DELTA;
	if (GetAsyncKeyState('W'))
		center += Vector2::Up() * SPEED * DELTA;
	if (GetAsyncKeyState('S'))
		center += Vector2::Down() * SPEED * DELTA;
}

void Player::ClampToScreenBounds()
{
	//Left
	if(center.x - radius < 0)
		center.x = radius;

	//Right
	if (center.x + radius > SCREEN_WIDTH)
		center.x = SCREEN_WIDTH - radius;

	//Top
	if (center.y - radius < 0)
		center.y = radius;

	//Bottom
	if (center.y + radius > SCREEN_HEIGHT)
		center.y = SCREEN_HEIGHT - radius;
}

void Player::UpdatePen()
{
	DeleteObject(hPen);

	if (isDamaged)
		hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	else
		hPen = CreatePen(PS_SOLID, 5, baseColor);
}

void Player::ColorEffect()
{
	if (!isDamaged) return;

	damageTimer += DELTA;
	if (damageTimer >= EFFECT_TIME)
	{
		damageTimer = 0.0f;
		isDamaged = false;
	}
}

void Player::DrawShieldEffect(HDC hdc)
{
	if (!isShield) return;

	HPEN oldPen = (HPEN)SelectObject(hdc, shieldPen);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, nullBrush);

	Ellipse(hdc, center.x - radius - 5, center.y - radius - 5, center.x + radius + 5, center.y + radius + 5);

	SelectObject(hdc, oldPen);
	SelectObject(hdc, oldBrush);
}


void Player::DrawLine(HDC hdc)
{
	firePos = { center.x, center.y - radius };
	POINT right = { center.x + radius, center.y + radius };
	POINT left = { center.x - radius, center.y + radius };

	HPEN defaultPen = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, firePos.x, firePos.y, nullptr);
	LineTo(hdc, right.x, right.y);

	MoveToEx(hdc, firePos.x, firePos.y, nullptr);
	LineTo(hdc, left.x, left.y);

	MoveToEx(hdc, center.x, center.y + (radius >> 1), nullptr);
	LineTo(hdc, right.x, right.y);

	MoveToEx(hdc, center.x, center.y + (radius >> 1), nullptr);
	LineTo(hdc, left.x, left.y);

	SelectObject(hdc, defaultPen);
}

COLORREF Player::GetColor()
{
	COLORREF bulletColor = (damage > baseDamage) ? COLOR_PLAYER_POWERED : COLOR_PLAYER_NORMAL;
	return bulletColor;
}

