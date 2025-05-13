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
        // ������ ������ �߻� ��ġ�� ���
        Vector2 firePosition = center + (direction.GetNormalized() * BARREL_SIZE); // ���� �߽ɿ��� ȸ���� �� ��ġ

        // ȸ���� offset�� ���ϱ� ���� ���� �������� ��� ��ġ ���
        Vector2 offset = firePosition - center; // center�� �������� �� ������� ��ġ

        // ȸ���� ������� ��ġ�� ����
//        Vector2 rotatedOffset = offset.Rotate(angle);  // ȸ���� ������� ��ġ (�ð�������� 90�� ȸ��)

        // ȸ���� ��ġ
//        Vector2 rotatedFirePosition = center + rotatedOffset;
        Vector2 rotatedFirePosition = center + offset;
        // �Ѿ� �߻�
        BulletManager::Get()->Fire(rotatedFirePosition, "Enemy", damage, COLOR_ENEMY_BULLET, direction);
    }
}
