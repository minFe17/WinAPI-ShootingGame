#include "Framework.h"

void ChoiceCharacterScene::Update()
{
	for (int i = 0; i < _buttons.size(); i++)
		_buttons[i]->Update();
}

ChoiceCharacterScene::ChoiceCharacterScene()
{
	_buttons.push_back(new NormalPlayerButton());
	_buttons.push_back(new HeavyPlayerButton());
	_buttons.push_back(new HomingPlayerButton());
}

void ChoiceCharacterScene::Render(HDC hdc)
{
	for (int i = 0; i < _buttons.size(); i++)
		_buttons[i]->Render(hdc);
}
