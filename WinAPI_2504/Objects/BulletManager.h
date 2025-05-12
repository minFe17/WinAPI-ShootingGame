#pragma once

class BulletManager : public Singleton<BulletManager>
{
	friend class Singleton;

private:
	const int BULLET_POOL_SIZE = 100;	

private:
	BulletManager();
	~BulletManager();

public:
	void Update(Player* player);
	void Render(HDC hdc);

	bool IsCollision(PolygonVector* circle, string tag);
	void Fire(Vector2 pos, string tag,int damage, COLORREF color,Vector2 direction = Vector2::Up());

	Bullet* GetCollidedBullet(Circle* circle, string tag);
	Bullet* GetLastFired();

private:
	vector<Bullet*> bullets;	
};