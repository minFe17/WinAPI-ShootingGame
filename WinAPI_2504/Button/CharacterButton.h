#pragma once

class CharacterButton : public Button
{
private:
	int FONT_SIZE = 30;

public:
	CharacterButton();
	void Update() override;
	void Render(HDC hdc) override;

private:
	void ShowSelectButton(HDC hdc);
	wstring PlayerText(EPlayerType type);

protected:
	Player* _player;
	EPlayerType _type;

private:
	HFONT _textFont = CreateFont(FONT_SIZE, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH || FF_DONTCARE, L"¸¼Àº °íµñ");
};