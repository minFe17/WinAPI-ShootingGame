#pragma once

class ChoiceCharacterScene : public Scene
{
public:
	ChoiceCharacterScene();
	void Update() override;
	void Render(HDC hdc) override;

private:
	void InitPlayers();

private:
	vector<CharacterButton*> _buttons;
	vector<Player*> _players;
	vector<RECT> _buttonPos;
};