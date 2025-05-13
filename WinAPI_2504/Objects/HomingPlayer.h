#pragma once

class HomingPlayer : public Player
{
private:
    const int HOMING_DAMAGE = 10;
	const float COOL_TIME = 0.3f;
public:
    HomingPlayer();
    ~HomingPlayer();

    void Fire() override;
private:
    
};
