#pragma once

class EnemyKamikaze : public Enemy
{
private:
    const int SPEED = 200;
    const int MAX_HP = 5;
    const int RADIUS = 10;
    const int DAMAGE = 10;
    const float DAMAGE_INTERVAL = 0.1f;
    const float CHARGE_SPEED = 400.0f;
    const float CHARGE_DISTANCE = 300.0f;

public:
    EnemyKamikaze();
    ~EnemyKamikaze();

    void Update();
    void Render(HDC hdc);
    void Spawn(Vector2 pos);
    void SetPlayer(Player* player) { this->player = player; }

private:
    void Move();
    void CheckExplosion();

private:

    bool isCharging = false;
    float chargeTimer = 0;

    HBRUSH hRedBrush;
    HBRUSH hBlueBrush;
    HBRUSH hSelectBrush;

};