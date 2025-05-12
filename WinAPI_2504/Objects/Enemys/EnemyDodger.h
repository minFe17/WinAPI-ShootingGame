#pragma once

class EnemyDodger : public Enemy
{
private:
    const int SPEED = 50;    
    const int MAX_HP = 20;
    const int RADIUS = 10;
    const int DAMAGE = 10;
    const float DAMAGE_INTERVAL = 0.1f;
    const float FIRE_INTERVAL = 1.5f;
    const float ZIGZAG_SPEED = 3.0f;
    const float ZIGZAG_RANGE = 200.0f;
    const float BULLET_SPEED = 200;

public:
    EnemyDodger();
    ~EnemyDodger();

    void Update();
    void Render(HDC hdc);
    void Spawn(Vector2 pos);
    void SetPlayer(Player* player) { this->player = player; }

private:
    void Move();
    void Fire();

private:
    float fireTimer = 0;
    float zigzagTimer = 0;
}; 