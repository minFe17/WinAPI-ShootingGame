#include "Framework.h"

void GameClearScene::Update()
{
}

void GameClearScene::Render(HDC hdc)
{
	RECT textPosition = { 100, 200, SCREEN_WIDTH, SCREEN_HEIGHT };

	SelectObject(hdc, _font);
	SetBkMode(hdc, TRANSPARENT);

	DrawTextW(hdc, TEXT.c_str(), -1, &textPosition,
		DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// 점수
	RECT scorePosition = { 150, 350, 600, 800 };
	SelectObject(hdc, _scoreFont);

	wstring score = to_wstring(ScoreManager::Get()->GetScore());
	wstring text = L"점수 : " + score;

	DrawTextW(hdc, text.c_str(), -1, &scorePosition,
		DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
