#include "Framework.h"

EnemyDodger::EnemyDodger() : Enemy()
{
    hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
    hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
    hSelectBrush = hBlueBrush;

    AddVertexs({ (float)-RADIUS, 0 });
    AddVertexs({ (float)RADIUS, 0 });
    AddVertexs({ 0, (float)RADIUS });
}

EnemyDodger::~EnemyDodger()
{
    DeleteObject(hRedBrush);
    DeleteObject(hBlueBrush);
}

void EnemyDodger::Update()
{
    if (!isActive) return;

    Move();
//    Damage();
    Fire();
}

void EnemyDodger::Render(HDC hdc)
{
    if (!isActive) return;

    HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);
    //    Circle::Render(hdc);
    /*
    POINT vertex[3] = {
        {center.x - radius,center.y},
        {center.x + radius,center.y},
        {center.x,center.y + radius}
    };*/

    DrawPolygon(hdc, vertexs);

    SelectObject(hdc, defaultBrush);
}

void EnemyDodger::Spawn(Vector2 pos)
{
    center = pos;
    isActive = true;
    hSelectBrush = hBlueBrush;
    hp = MAX_HP;
    zigzagTimer = 0;
    radius = RADIUS;
    damage = DAMAGE;
}

void EnemyDodger::Move()
{
    zigzagTimer += DELTA;
    float offset = sin(zigzagTimer * ZIGZAG_SPEED) * ZIGZAG_RANGE;
    
    center.x += offset * DELTA;
    center.y += SPEED * DELTA;

    if (center.y > SCREEN_HEIGHT)
    {
        isActive = false;
    }
}

void EnemyDodger::Fire()
{
    fireTimer += DELTA;

    if (fireTimer >= FIRE_INTERVAL)
    {
        fireTimer = 0.0f;
        BulletManager::Get()->Fire(center + Vector2{0,(float)radius}, "Enemy", damage, COLOR_ENEMY_BULLET,Vector2::Down());
    }
}  