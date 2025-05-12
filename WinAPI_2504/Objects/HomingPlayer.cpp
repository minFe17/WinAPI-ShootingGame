#include "Framework.h"

HomingPlayer::HomingPlayer()
{
    fireCooldown = 0.3f;
    baseDamage = 20;
    damage = baseDamage;
    baseColor = RGB(50, 100, 200);
}

HomingPlayer::~HomingPlayer()
{
}


void HomingPlayer::Fire()
{
    BulletCount();

    const float TOTAL_SPREAD = 5.0f; 
    int count = (int)firePosList.size();

    for (int i = 0; i < count; ++i)
    {
        Vector2 pos = firePosList[i];

        float angleDeg = -90.0f; 
        if (count > 1)
        {
            int centerIndex = count / 2;
            int offset = i - centerIndex;

            float angleStep = TOTAL_SPREAD / (count - 1);
            angleDeg += offset * angleStep;
        }

        float angleRad = angleDeg * (PI / 180.0f);
        Vector2 dir = Vector2(cosf(angleRad), sinf(angleRad));

        BulletManager::Get()->Fire(pos, "Player", damage, GetColor(), dir);

        Bullet* bullet = BulletManager::Get()->GetLastFired();
        if (bullet)
        {
            bullet->SetHasRedirected(false); 
        }
    }
}

