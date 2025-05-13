#include "Framework.h"

void ChoiceCharacterScene::Update()
{
	for (int i = 0; i < _buttons.size(); i++)
		_buttons[i]->Update();
}

ChoiceCharacterScene::ChoiceCharacterScene()
{
	InitPlayers();
	for (int i = 0; i < (int)EPlayerType::Max; i++)
		_buttons.push_back(new CharacterButton(_players[i], (EPlayerType)i, _buttonPos[i]));
}

void ChoiceCharacterScene::Render(HDC hdc)
{
	for (int i = 0; i < _buttons.size(); i++)
		_buttons[i]->Render(hdc);
}

void ChoiceCharacterScene::InitPlayers()
{
	_players.push_back(new NormalPlayer());
	_players.push_back(new HeavyPlayer());
	_players.push_back(new HomingPlayer());

	_buttonPos.push_back({ 20, 300, 193, 500 });
	_buttonPos.push_back({ 213, 300, 386, 500 });
	_buttonPos.push_back({ 406, 300, 579, 500 });
}