#include "Framework.h"

void GameClearScene::Update()
{
}

void GameClearScene::Render(HDC hdc)
{
	RECT textPosition = { 0, 200, 600, 800 };

	SelectObject(hdc, _font);
	DrawTextW(hdc, TEXT, -1, &textPosition,
		DT_CENTER | DT_VCENTER | DT_WORDBREAK);


	// ����
	RECT scorePosition = { 0, 400, 600, 800 };
	SelectObject(hdc, _scoreFont);

	wstring score = to_wstring(ScoreManager::Get()->GetScore());
	wstring text = L"���� : " + score;
	DrawTextW(hdc, text.c_str(), -1, &scorePosition,
		DT_CENTER | DT_VCENTER | DT_WORDBREAK);
}
