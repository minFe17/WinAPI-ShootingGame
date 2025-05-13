#pragma once
class HeavyPlayer : public Player
{
private:
    const int HEAVY_DAMAGE = 30;
    const float COOL_TIME = 1.0f;
public:
    HeavyPlayer();
    ~HeavyPlayer();

    void Fire() override;
private:
    
};
