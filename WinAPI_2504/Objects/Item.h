#pragma once

//#include "Framework.h"
class Item : public Circle
{
public:
	Item();
	~Item();

	void Update();
	void Render(HDC hdc);
	void Spawn(Vector2 pos) { center = pos; isActive = true; }

	ItemType GetType() { return type; }
	void SetType(ItemType type) { this->type = type; }
	void SetPosition(Vector2 pos) { center = pos; }
private:
	ItemType type;

	HBRUSH brush;
};