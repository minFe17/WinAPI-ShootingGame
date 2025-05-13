#pragma once

class LobbyButton : public Button
{
private:
	const int CENTER_X = SCREEN_WIDTH / 2;
public:
	LobbyButton();
	void Update() override;
	void Render(HDC hdc) override;

private:
	void SetPlayButton(HDC hdc);
};