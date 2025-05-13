#include "Framework.h"

EnemyGrunt::EnemyGrunt() : Enemy()
{
    hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
    hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
    hSelectBrush = hBlueBrush;
    hPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
    vertexs.resize(4);

    AddVertexs({ 0.0f, 4.0f });
    AddVertexs({ BARREL_SIZE * 1.0f, 4.0f });
    AddVertexs({ BARREL_SIZE * 1.0f, -4.0f });
    AddVertexs({ 0.0f, -4.0f });

}

EnemyGrunt::~EnemyGrunt()
{
    DeleteObject(hRedBrush);
    DeleteObject(hBlueBrush);
}

void EnemyGrunt::Render(HDC hdc)
{
    if (!isActive) return;
    ChangeColor();
    HPEN defaultPen = (HPEN)SelectObject(hdc, hPen);
    HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);
    Circle::Render(hdc);

    DrawRotatedRectangle(hdc, vertexs, angle);

    SelectObject(hdc, defaultPen);
    SelectObject(hdc, defaultBrush);
}

void EnemyGrunt::Spawn(Vector2 pos)
{
    center = pos;
    isActive = true;
    hSelectBrush = hBlueBrush;
    hp = MAX_HP;
    isDamaged = false;
    radius = RADIUS;
    damage = DAMAGE;

}

void EnemyGrunt::Move()
{
    center.y += SPEED * DELTA;
    direction = player->GetCenter() - center;
    angle = atan2(direction.y, direction.x);
    if (center.y > SCREEN_HEIGHT)
    {
        isActive = false;
    }
}

void EnemyGrunt::Fire()
{
    fireTimer += DELTA;

    if (fireTimer >= FIRE_INTERVAL)
    {
        fireTimer = 0.0f;
        // 포대의 끝에서 발사 위치를 계산
        Vector2 firePosition = center + (direction.GetNormalized() * BARREL_SIZE); // 포대 중심에서 회전된 끝 위치

        // 회전된 offset을 구하기 위해 포대 끝에서의 상대 위치 계산
        Vector2 offset = firePosition - center; // center를 기준으로 한 상대적인 위치

        // 회전된 상대적인 위치를 구함
//        Vector2 rotatedOffset = offset.Rotate(angle);  // 회전된 상대적인 위치 (시계방향으로 90도 회전)

        // 회전된 위치
//        Vector2 rotatedFirePosition = center + rotatedOffset;
        Vector2 rotatedFirePosition = center + offset;
        // 총알 발사
        BulletManager::Get()->Fire(rotatedFirePosition, "Enemy", damage, COLOR_ENEMY_BULLET, direction);
    }
}
