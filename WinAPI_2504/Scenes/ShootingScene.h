#pragma once

class ShootingScene : public Scene
{
private:
	int SCORE_FONT_SIZE = 50;
public:
	ShootingScene();
	~ShootingScene();

	void Update() override;
	void Render(HDC hdc) override;
	void SetPlayer(Player* player) { this->player = player; }

private:
	void ShowScore(HDC hdc);
	void ShowHP(HDC hdc);
	void DrawPlayerIcon(HDC hdc);

private:
	int _playerIconRadius = 20;
	Vector2 _playerIconCenter = { 30, 30 };
	Vector2 scorePosition = { SCREEN_WIDTH / 2, 50 };
	Player* player;	
	HFONT _scoreFont = CreateFont(SCORE_FONT_SIZE, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
								  DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
								  DEFAULT_QUALITY, DEFAULT_PITCH || FF_DONTCARE, L"¸¼Àº °íµñ");

};