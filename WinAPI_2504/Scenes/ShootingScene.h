#pragma once

class ShootingScene : public Scene
{
public:
	ShootingScene();
	~ShootingScene();

	void Update() override;
	void Render(HDC hdc) override;
	void SetPlayer(Player* player) { this->player = player; }

private:
	Player* player;	
};