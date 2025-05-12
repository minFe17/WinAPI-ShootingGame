#include "Framework.h"

Item::Item() : Circle(15)
{
	isActive = true;
	//type = ItemType::MultiShot;
}

Item::~Item()
{
}

void Item::Update()
{
	center.y += 100 * DELTA;
	if (center.y > SCREEN_HEIGHT)
	{
		isActive = false;
	}
}

void Item::Render(HDC hdc)
{
	if (!isActive) return;
	switch (type)
	{
	case ItemType::MultiShot:
		brush = CreateSolidBrush(RGB(255, 255, 0)); break;
	case ItemType::PowerUp:
		brush = CreateSolidBrush(RGB(255, 0, 255)); break;
	case ItemType::Shield:
		brush = CreateSolidBrush(RGB(0, 255, 255)); break;
	}

	HBRUSH old = (HBRUSH)SelectObject(hdc, brush);
	Circle::Render(hdc);
	SelectObject(hdc, old);
	DeleteObject(brush);

}
