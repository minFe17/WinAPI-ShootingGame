#pragma once

class CharacterButton : public Button
{
private:
	int FONT_SIZE = 30;

public:
	CharacterButton(Player* player, EPlayerType type, RECT rect);
	void Update() override;
	void Render(HDC hdc) override;

private:
	void ShowSelectButton(HDC hdc);
	wstring PlayerText(EPlayerType type);

private:
	Player* _player;
	EPlayerType _type;
	HFONT _textFont = CreateFont(FONT_SIZE, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH || FF_DONTCARE, L"¸¼Àº °íµñ");
};