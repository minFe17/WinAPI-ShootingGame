#include "Framework.h"

HomingPlayerButton::HomingPlayerButton()
{
	_player = new HomingPlayer();
	_type = EPlayerType::Homing;
	_button = { 406, 300, 579, 500 };
}

HomingPlayerButton::~HomingPlayerButton()
{
	delete _player;
}
