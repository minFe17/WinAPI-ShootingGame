#include "Framework.h"

EnemyKamikaze::EnemyKamikaze() : Enemy()
{
    hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
    hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
    hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
    hSelectBrush = hBlueBrush;
}

EnemyKamikaze::~EnemyKamikaze()
{
    DeleteObject(hRedBrush);
    DeleteObject(hBlueBrush);
}

void EnemyKamikaze::Update()
{
    if (!isActive) return;

    Move();
    Damage();
    CheckExplosion();
}

void EnemyKamikaze::Render(HDC hdc)
{
    if (!isActive) return;
    ChangeColor();
    HPEN defaultPen = (HPEN)SelectObject(hdc, hPen);
    HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);
    Circle::Render(hdc);
    SelectObject(hdc, defaultPen);
    SelectObject(hdc, defaultBrush);
}

void EnemyKamikaze::Spawn(Vector2 pos)
{
    center = pos;
    isActive = true;
    hSelectBrush = hBlueBrush;
    hp = MAX_HP;
    isCharging = false;
    chargeTimer = 0;
    radius = RADIUS;
    damage = DAMAGE;
}


void EnemyKamikaze::Move()
{
    if (!isCharging)
    {
        center.y += SPEED * DELTA;
        // 플레이어와의 거리가 CHARGE_DISTANCE 이하일 때 돌진 시작
        if (player)
        {
            Vector2 toPlayer = player->GetCenter() - center;
            if (toPlayer.Magnitude() <= CHARGE_DISTANCE)
            {
                isCharging = true;
                chargeTimer = 0;
            }
        }
    }
    else
    {
        hSelectBrush = hRedBrush;

        // 플레이어를 향해 돌진
        Vector2 toPlayer = player->GetCenter() - center;
        toPlayer.Normalize();
        center += toPlayer * CHARGE_SPEED * DELTA;
    }

    if (center.y > SCREEN_HEIGHT)
    {
        isActive = false;
    }
}

void EnemyKamikaze::CheckExplosion()
{
    if (!isCharging || !player) return;

    // 플레이어와 충돌 시 폭발
    if (IsCollisionCircle(player))
    {
        // 플레이어에게 데미지 주기
        player->HitEnemy();
        isActive = false;
    }
}