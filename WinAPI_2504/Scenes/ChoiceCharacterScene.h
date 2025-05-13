#pragma once

class ChoiceCharacterScene : public Scene
{
public:
	ChoiceCharacterScene();
	void Update() override;
	void Render(HDC hdc) override;

private:
	vector<CharacterButton*> _buttons;
};