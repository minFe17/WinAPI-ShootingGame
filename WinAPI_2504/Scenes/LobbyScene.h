#pragma once

class LobbyScene : public Scene
{
public:
	void Update() override;
	void Render(HDC hdc) override;
	void SetPlayButton(HDC hdc);

private:
	void TriggerPlayButton();

private:
	bool _isTriggerPlayButton;
	bool _isShowUI;
	string _title;
	RECT _playButton;
	HBRUSH _buttonBrush = CreateSolidBrush(RGB(75, 227, 131));
	HBRUSH _triggerButtonBrush = CreateSolidBrush(RGB(58, 166, 98));
};