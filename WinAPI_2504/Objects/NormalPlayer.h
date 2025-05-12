#pragma once

class NormalPlayer : public Player
{
public:
    NormalPlayer() {
        baseColor = RGB(100, 230, 150);
        fireCooldown = 0.0f;
    };
    ~NormalPlayer() = default;
};
