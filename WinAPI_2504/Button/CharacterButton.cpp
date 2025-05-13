#include "Framework.h"

CharacterButton::CharacterButton()
{
	_brush = CreateSolidBrush(RGB(63, 193, 232));
	_triggerBrush = CreateSolidBrush(RGB(64, 168, 199));
}

void CharacterButton::Update()
{
	TriggerButton();
	if (_isTrigger && Input::Get()->IsKeyDown(VK_LBUTTON))
	{
		SceneManager::Get()->InitInGamePlayer(_player);
		SceneManager::Get()->SetSceneType(ESceneType::InGame);
	}
}

void CharacterButton::Render(HDC hdc)
{
	ShowSelectButton(hdc);
}

void CharacterButton::ShowSelectButton(HDC hdc)
{
	DrawRect(hdc);

	SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
	SelectObject(hdc, _textFont);

	
	wstring text = PlayerText(_type);
	SetBkMode(hdc, TRANSPARENT);

	RECT textPosition = { _button.left + 30, _button.top + 30, _button.right + 30, _button.bottom + 30 };
	DrawTextW(hdc, text.c_str(), -1, &textPosition,
		DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hBrush);

	DeleteObject(hBrush);
}

wstring CharacterButton::PlayerText(EPlayerType type)
{
	switch (type)
	{
	case EPlayerType::Normal:
		return L"Normal";
	case EPlayerType::Heavy:
		return L"Heavy";
	case EPlayerType::Homing:
		return L"Homing";
	}
}