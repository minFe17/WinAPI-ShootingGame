#include "Framework.h"

Bullet::Bullet()
{
    radius = 10;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
    if (!isActive) return;

    if (!hasRedirected)
    {
        Vector2 move = direction * SPEED * DELTA;
        travelDistance += move.Magnitude();

        if (travelDistance >= REDIRECT_DISTANCE)
        {
            Enemy* closest = EnemyManager::Get()->GetClosestEnemy(center);
            if (closest && closest->IsActive())
            {
                Vector2 toTarget = closest->GetCenter() - center;
                direction = toTarget.GetNormalized();
            }
            hasRedirected = true;
        }
    }

    center += direction * SPEED * DELTA;

    if (center.y < 0 || center.y > SCREEN_HEIGHT ||
        center.x < 0 || center.x > SCREEN_WIDTH)
    {
        isActive = false;
    }
}

void Bullet::Render(HDC hdc)
{
    if (!isActive) return;

    HBRUSH brush = CreateSolidBrush(bulletColor);
    HBRUSH old = (HBRUSH)SelectObject(hdc, brush);

    Ellipse(hdc,
        center.x - radius, center.y - radius,
        center.x + radius, center.y + radius);

    SelectObject(hdc, old);
    DeleteObject(brush);
}

