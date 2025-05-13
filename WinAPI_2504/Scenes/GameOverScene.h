#pragma once

class GameOverScene : public Scene
{
private:
	const int FONT_SIZE = 100;
	const wchar_t* TEXT = L"Game\nOver";
public:
	void Update() override;
	void Render(HDC hdc) override;

private:
	wstring _firstLineText = L"Game";
	wstring _secondLineText = L"Clear";
	Vector2 _firstLinePos = { 300, 300 };
	Vector2 _secondLinePos = { 300, 400 };
	HFONT _font = CreateFont(FONT_SIZE, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"¸¼Àº °íµñ");
};