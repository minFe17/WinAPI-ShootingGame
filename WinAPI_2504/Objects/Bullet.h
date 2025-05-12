#pragma once

class Enemy;

class Bullet : public PolygonVector
{
private:
	const float SPEED = 500;
	const float REDIRECT_DISTANCE = 100.0f;

public:
	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 pos, Vector2 direction = Vector2::Up())
	{
		this->direction = direction.GetNormalized();
		isActive = true;
		center = pos;

		travelDistance = 0.0f;
		hasRedirected = true;
	}

	string GetTag() { return tag; }
	void SetTag(string tag) { this->tag = tag; }	

	int GetDamage() const { return damage; }
	void SetDamage(int attackDamage) { damage = attackDamage; }
	void SetHasRedirected(bool value) { hasRedirected = value; }
	void SetColor(COLORREF color) { bulletColor = color; }

	
private:	
	int damage = 10;
	float travelDistance = 0.0f;      
	bool hasRedirected = true;   

	string tag;
	Vector2 direction = Vector2::Up();
	COLORREF bulletColor = RGB(255, 255, 255);
};