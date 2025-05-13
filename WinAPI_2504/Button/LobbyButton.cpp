#include "Framework.h"

LobbyButton::LobbyButton()
{
	_brush = CreateSolidBrush(RGB(75, 227, 131));
	_triggerBrush = CreateSolidBrush(RGB(58, 166, 98));
	_button = { CENTER_X - 100, 600, CENTER_X + 100, 700 };

}

void LobbyButton::Update()
{
	TriggerButton();
	if (_isTrigger && Input::Get()->IsKeyDown(VK_LBUTTON))
		SceneManager::Get()->SetSceneType(ESceneType::ChoiceCharacter);
}

void LobbyButton::Render(HDC hdc)
{
	SetPlayButton(hdc);
}

void LobbyButton::SetPlayButton(HDC hdc)
{
	DrawRect(hdc);

	// 삼각형 그리기
	POINT triangle[3] = { { CENTER_X - 30, 630 }, { CENTER_X - 30, 670 }, { CENTER_X + 30, 650 } };
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hBrush);

	// 삼각형 내부 채우며 그림
	Polygon(hdc, triangle, 3);

	DeleteObject(hBrush);
}
