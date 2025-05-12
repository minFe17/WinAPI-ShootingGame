#include "Framework.h"

BulletManager::BulletManager()
{
	bullets.resize(BULLET_POOL_SIZE);
	for (Bullet*& bullet : bullets)
	{
		bullet = new Bullet();
		bullet->SetActive(false);
	}
}

BulletManager::~BulletManager()
{
	for (Bullet*& bullet : bullets)
	{
		delete bullet;
	}
	bullets.clear();
}

void BulletManager::Update(Player* player)
{
	for (Bullet*& bullet : bullets)
	{
		if (!bullet->IsActive()) continue;

		if (bullet->GetTag() == "Player")
		{
			for (Enemy* enemy : EnemyManager::Get()->GetEnemies())
			{
				if (!enemy->IsActive()) continue;

				if (bullet->IsCollisionCircle(enemy) || bullet->IsPolygonCircleCollision(enemy))
				{
					bullet->SetActive(false);
					enemy->Damage(bullet->GetDamage());
					break;
				}
			}
		}
		else if (bullet->GetTag() == "Enemy")
		{
			if (bullet->IsCollisionCircle(player))
			{
				bullet->SetActive(false);
				player->HitEnemy();
				break;
			}
		}
	}

	for (Bullet*& bullet : bullets)
	{
		if (bullet->IsActive())
			bullet->Update();
	}
}


void BulletManager::Render(HDC hdc)
{
	for (Bullet*& bullet : bullets)
	{
		bullet->Render(hdc);
	}
}


bool BulletManager::IsCollision(PolygonVector* circle, string tag)
{
	for (Bullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
			continue;
		if (bullet->GetTag() != tag)
			continue;
		if (bullet->IsCollisionCircle(circle) || bullet->IsPolygonCircleCollision(circle))
		{
			//다운 캐스팅
				//Enemy* enemy = (Enemy*)(circle);
				//enemy->Damage();

			bullet->SetActive(false);
			return true;
		}
	}

	return false;
}
void BulletManager::Fire(Vector2 pos, string tag,int damage, COLORREF color, Vector2 direction)
{
	for (Bullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			bullet->Fire(pos, direction);
			bullet->SetTag(tag);
			bullet->SetDamage(damage);
			bullet->SetColor(color);
			break;
		}
	}
}

Bullet* BulletManager::GetCollidedBullet(Circle* circle, string tag)
{

	for (Bullet* bullet : bullets)
	{
		if (!bullet->IsActive()) continue;
		if (bullet->GetTag() != tag) continue;

		if (bullet->IsCollisionCircle(circle))
		{
			bullet->SetActive(false);
			return bullet;
		}
	}
	return nullptr;
}

Bullet* BulletManager::GetLastFired()
{
	for (int i = (int)bullets.size() - 1; i >= 0; --i)
	{
		if (bullets[i]->IsActive())
			return bullets[i];
	}
	return nullptr;
}
