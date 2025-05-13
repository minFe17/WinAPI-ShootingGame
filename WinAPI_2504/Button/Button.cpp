#include "Framework.h"

void Button::TriggerButton()
{
	if (_button.left > mousePos.x || _button.right < mousePos.x)
	{
		_isTrigger = false;
		return;
	}
	if (_button.top > mousePos.y || _button.bottom < mousePos.y)
	{
		_isTrigger = false;
		return;
	}
	_isTrigger = true;
}

void Button::DrawRect(HDC hdc)
{
	if (_isTrigger)
		SelectObject(hdc, _triggerBrush);
	else
		SelectObject(hdc, _brush);

	Rectangle(hdc, _button.left, _button.top, _button.right, _button.bottom);
}
