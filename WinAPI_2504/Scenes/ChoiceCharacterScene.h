#pragma once

enum class EPlayerType
{
	Normal,
	Heavy,
	Homing,
	Max,
};

class ChoiceCharacterScene : public Scene
{
private:
	int FONT_SIZE = 30;
public:
	ChoiceCharacterScene();
	void Update() override;
	void Render(HDC hdc) override;

private:
	void InitPlayers();
	bool TriggerChoiceButton(RECT button);
	wstring PlayerText(EPlayerType type);

private:
	bool _isTriggerButton[(int)EPlayerType::Max];
	vector<Player*> _players;
	vector<RECT> _buttons;
	HBRUSH _buttonBrush = CreateSolidBrush(RGB(63, 193, 232));
	HBRUSH _triggerButtonBrush = CreateSolidBrush(RGB(64, 168, 199));
	HFONT _scoreFont = CreateFont(FONT_SIZE, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH || FF_DONTCARE, L"¸¼Àº °íµñ");
};