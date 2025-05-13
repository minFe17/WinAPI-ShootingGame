#include "Framework.h"

Item::Item() : Circle(15)
{
	isActive = true;
	MBrush = CreateSolidBrush(RGB(255, 255, 0));
	PBrush = CreateSolidBrush(RGB(255, 0, 255));
	SBrush = CreateSolidBrush(RGB(0, 255, 255));
}

Item::~Item()
{
	DeleteObject(MBrush);
	DeleteObject(PBrush);
	DeleteObject(SBrush);
	DeleteObject(brush);
}

void Item::Update()
{
	center.y += DOWN_SPEED * DELTA;
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
		brush = MBrush; break;
	case ItemType::PowerUp:
		brush = PBrush; break;
	case ItemType::Shield:
		brush = SBrush; break;
	}

	HBRUSH old = (HBRUSH)SelectObject(hdc, brush);
	Circle::Render(hdc);
	SelectObject(hdc, old);
}
