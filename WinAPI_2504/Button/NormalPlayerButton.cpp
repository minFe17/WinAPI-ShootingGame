#include "Framework.h"

NormalPlayerButton::NormalPlayerButton()
{
	_player = new NormalPlayer();
	_type = EPlayerType::Normal;
	_button = { 20, 300, 193, 500 };
}

NormalPlayerButton::~NormalPlayerButton()
{
	delete _player;
}
