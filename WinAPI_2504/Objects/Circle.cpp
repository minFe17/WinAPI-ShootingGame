#include "Framework.h"
#include "Circle.h"

Circle::Circle(int radius) : radius(radius)
{
}

Circle::~Circle()
{
}


void Circle::Render(HDC hdc)
{
	if (!isActive) return;

	Ellipse(hdc, 
		center.x - radius, center.y - radius,
		center.x + radius, center.y + radius
	);	
}

bool Circle::IsCollisionPoint(POINT point)
{
	int dx = center.x - point.x;
	int dy = center.y - point.y;

	return (dx * dx + dy * dy) <= (radius * radius);
}

bool Circle::IsCollisionCircle(Circle* circle)
{
	int dx = center.x - circle->center.x;
	int dy = center.y - circle->center.y;

	return (dx * dx + dy * dy) <= ((radius + circle->radius) * (radius + circle->radius));	
}
