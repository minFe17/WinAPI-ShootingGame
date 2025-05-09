#pragma once

class LobbyScene : public Scene
{
public:
	void Update() override;
	void Render(HDC hdc) override;
	void SetPlayButton();

private:
	void TriggerEnterPlayButton();
	void TriggerExitPlayButton();
	void ShowTitle();

private:
	bool _isTriggerPlayButton;
	bool _isShowUI;
	string _title;
	RECT _playButton;
};