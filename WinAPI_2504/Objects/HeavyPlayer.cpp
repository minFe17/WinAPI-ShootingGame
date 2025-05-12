#include "Framework.h"

HeavyPlayer::HeavyPlayer()
{
    fireCooldown = 1.0f;
    baseDamage = 30;
    damage = baseDamage;
    baseColor = RGB(100, 50, 100);
}

HeavyPlayer::~HeavyPlayer()
{
}


void HeavyPlayer::Fire()
{
    BulletCount();

    const float TOTAL_SPREAD = 6.0f; 
    int count = (int)firePosList.size();

    for (int i = 0; i < count; ++i)
    {
        Vector2 pos = firePosList[i];
        float angleDeg = -90.0f;
        if (count > 1)
        {
            int centerIndex = count / 2;
            int indexOffset = i - centerIndex;
            float angleStep = TOTAL_SPREAD / (count - 1);
            angleDeg += angleStep * indexOffset;
        }

        float angleRad = angleDeg * (PI / 180.0f);
        Vector2 dir(cosf(angleRad), sinf(angleRad));
        BulletManager::Get()->Fire(pos, "Player", damage,GetColor(), dir);
        Bullet* bullet = BulletManager::Get()->GetLastFired();
        if (bullet)
        {
            bullet->SetDamage(30); 
        }
    }
}
