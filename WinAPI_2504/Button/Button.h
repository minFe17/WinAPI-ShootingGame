#pragma once

class Button
{
public:
	Button() = default;
	~Button() = default;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;

protected:
	void TriggerButton();
	void DrawRect(HDC hdc);

protected:
	bool _isTrigger;
	RECT _button;
	HBRUSH _triggerBrush;
	HBRUSH _brush;
};