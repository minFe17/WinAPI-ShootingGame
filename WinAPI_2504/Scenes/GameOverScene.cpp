#include "Framework.h"

void GameOverScene::Update()
{

}

void GameOverScene::Render(HDC hdc)
{
	SelectObject(hdc, _font);
	TextOut(hdc, _firstLinePos.x, _firstLinePos.y, _firstLineText.c_str(), _firstLineText.size());
	TextOut(hdc, _secondLinePos.x, _secondLinePos.y, _secondLineText.c_str(), _secondLineText.size());
}
