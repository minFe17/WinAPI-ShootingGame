#pragma once

enum class PlayerType
{
	DFG,
	Max,
};

class ChoiceCharacterScene : public Scene
{
public:
	ChoiceCharacterScene();
	void Update() override;
	void Render(HDC hdc) override;

private:
	void InitPlayers();
	bool TriggerChoiceButton(RECT button);

private:
	bool _isTriggerButton[(int)PlayerType::Max];
	vector<Player*> _players;
	vector<RECT> _buttons;
	HBRUSH _buttonBrush = CreateSolidBrush(RGB(63, 193, 232));
	HBRUSH _triggerButtonBrush = CreateSolidBrush(RGB(64, 168, 199));

};