#include "Framework.h"

HeavyPlayerButton::HeavyPlayerButton()
{
	_player = new HeavyPlayer();
	_type = EPlayerType::Heavy;
	_button = { 213, 300, 386, 500 };
}

HeavyPlayerButton::~HeavyPlayerButton()
{
	delete _player;
}
