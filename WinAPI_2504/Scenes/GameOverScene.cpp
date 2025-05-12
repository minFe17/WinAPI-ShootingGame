#include "Framework.h"

void GameOverScene::Update()
{

}

void GameOverScene::Render(HDC hdc)
{
	RECT rect = { 0, 250, 600, 800 };

	SelectObject(hdc, _font);
	DrawTextW(hdc, TEXT, -1, &rect,
		DT_CENTER | DT_VCENTER | DT_WORDBREAK);
}
