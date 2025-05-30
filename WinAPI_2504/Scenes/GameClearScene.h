#pragma once

class GameClearScene : public Scene
{
private:
	const int FONT_SIZE = 100;
	int SCORE_FONT_SIZE = 50;
	const wchar_t* TEXT = L"Game\nClear";

public:
	void Update() override;
	void Render(HDC hdc) override;
private:
	HFONT _font = CreateFont(FONT_SIZE, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"���� ����");
	HFONT _scoreFont = CreateFont(SCORE_FONT_SIZE, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH || FF_DONTCARE, L"���� ����");
};