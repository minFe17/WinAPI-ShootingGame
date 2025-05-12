#include "Framework.h"

void ChoiceCharacterScene::Update()
{
	for (int i = 0; i < _buttons.size(); i++)
	{
		if (_isTriggerButton[i] && Input::Get()->IsKeyDown(VK_LBUTTON))
		{
			SceneManager::Get()->InitInGamePlayer(new Player);
			//SceneManager::Get()->InitInGamePlayer(_players[i]);
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

		Rectangle(hdc, _buttons[i].left, _buttons[i].top, _buttons[i].right, _buttons[i].bottom);
	}

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hBrush);

	DeleteObject(hBrush);
}

void ChoiceCharacterScene::InitPlayers()
{
	//_players.push_back(new NormalPlayer());
	_buttons.push_back({ 20, 300, 193, 500 });
	_buttons.push_back({ 213, 300, 386, 500 });
	_buttons.push_back({ 406, 300, 579, 500 });
}

bool ChoiceCharacterScene::TriggerChoiceButton(RECT button)
{
	if (button.left > mousePos.x || button.right < mousePos.x)
		return false;
	if (button.top > mousePos.y || button.bottom < mousePos.y)
		return false;
	return true;
}