#include "Framework.h"

void ChoiceCharacterScene::Update()
{
	for (int i = 0; i < _buttons.size(); i++)
	{
		if (_isTriggerButton[i] && Input::Get()->IsKeyDown(VK_LBUTTON))
		{
			SceneManager::Get()->InitInGamePlayer(_players[i]);
			SceneManager::Get()->SetSceneType(ESceneType::InGame);
		}
	}
}

ChoiceCharacterScene::ChoiceCharacterScene()
{
	InitPlayers();
}

void ChoiceCharacterScene::Render(HDC hdc)
{
	for (int i = 0; i < _buttons.size(); i++)
	{
		if (TriggerChoiceButton(_buttons[i]))
		{
			_isTriggerButton[i] = true;
			SelectObject(hdc, _triggerButtonBrush);
		}
		else
		{
			_isTriggerButton[i] = false;
			SelectObject(hdc, _buttonBrush);
		}

		SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
		SelectObject(hdc, _scoreFont);

		Rectangle(hdc, _buttons[i].left, _buttons[i].top, _buttons[i].right, _buttons[i].bottom);

		wstring text = PlayerText((EPlayerType)i);
		SetBkMode(hdc, TRANSPARENT);
		RECT textPosition = { _buttons[i].left+30, _buttons[i].top+30, _buttons[i].right + 30, _buttons[i].bottom + 30 };
		DrawTextW(hdc, text.c_str(), -1, &textPosition,
			DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hBrush);

	DeleteObject(hBrush);
}

void ChoiceCharacterScene::InitPlayers()
{
	_players.push_back(new NormalPlayer());
	_players.push_back(new HeavyPlayer());
	_players.push_back(new HomingPlayer());

	_buttons.push_back({ 20, 300, 193, 500 });
	_buttons.push_back({ 213, 300, 386, 500 });
	_buttons.push_back({ 406, 300, 579, 500 });
}

wstring ChoiceCharacterScene::PlayerText(EPlayerType type)
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

bool ChoiceCharacterScene::TriggerChoiceButton(RECT button)
{
	if (button.left > mousePos.x || button.right < mousePos.x)
		return false;
	if (button.top > mousePos.y || button.bottom < mousePos.y)
		return false;
	return true;
}