#pragma once


class EnemyGrunt : public Enemy
{
private:
    const int SPEED = 30;    
    const int MAX_HP = 30;
    const int RADIUS = 10;
    const int DAMAGE = 10;
    const float DAMAGE_INTERVAL = 0.1f;
    const float FIRE_INTERVAL = 2.0f;
    const float BULLET_SPEED = 100;
    const float BARREL_SIZE = 30;
public:
    EnemyGrunt();
    ~EnemyGrunt();

    void Update();
    void Render(HDC hdc);
    void Spawn(Vector2 pos);
    void SetPlayer(Player* player) { this->player = player; }

private:
//    void Damage();
    void Move();
    void Fire();


private:
//    int hp = 0;
    float damageTimer = 0;
    float fireTimer = 0;
    float angle = 0;
    bool isDamaged = false;    
    /*
    HBRUSH hRedBrush;
    HBRUSH hBlueBrush;
    HBRUSH hSelectBrush;    
    */
    Vector2 direction;
}; 