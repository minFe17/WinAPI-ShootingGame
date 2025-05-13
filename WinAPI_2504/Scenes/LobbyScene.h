#pragma once

class LobbyScene : public Scene
{
public:
	void Update() override;
	void Render(HDC hdc) override;

private:
	//void TriggerPlayButton();
	//void SetPlayButton(HDC hdc);

private:
	LobbyButton lobbyButton = LobbyButton();
	/*bool _isTriggerPlayButton;
	RECT _playButton;
	HBRUSH _buttonBrush = CreateSolidBrush(RGB(75, 227, 131));
	HBRUSH _triggerButtonBrush = CreateSolidBrush(RGB(58, 166, 98));*/
};