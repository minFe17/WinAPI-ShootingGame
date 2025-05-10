#include "Framework.h"

void LobbyScene::Update()
{
	TriggerPlayButton();

	if (_isTriggerPlayButton && Input::Get()->IsKeyDown(VK_LBUTTON))
		SceneManager::Get()->SetSceneType(SceneType::ChoiceCharacter);
}

void LobbyScene::Render(HDC hdc)
{
	SetPlayButton(hdc);
}

void LobbyScene::SetPlayButton(HDC hdc)
{
	int centerX = SCREEN_WIDTH / 2;

	if (_isTriggerPlayButton)
		SelectObject(hdc, _triggerButtonBrush);
	else
		SelectObject(hdc, _buttonBrush);

	_playButton = { centerX - 100, 600, centerX + 100, 700 };
	Rectangle(hdc, _playButton.left, _playButton.top, _playButton.right, _playButton.bottom);

	// 삼각형 그리기
	POINT triangle[3] = { { centerX - 30, 630 }, { centerX - 30, 670 }, { centerX + 30, 650 } };
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hBrush);

	// 삼각형 내부 채우며 그림
	Polygon(hdc, triangle, 3);

	DeleteObject(hBrush);
}

void LobbyScene::TriggerPlayButton()
{
	if (_playButton.left > mousePos.x || _playButton.right < mousePos.x)
	{
		_isTriggerPlayButton = false;
		return;
	}
	if (_playButton.top > mousePos.y || _playButton.bottom < mousePos.y)
	{
		_isTriggerPlayButton = false;
		return;
	}
	_isTriggerPlayButton = true;
}