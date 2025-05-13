#include "Framework.h"

void LobbyScene::Update()
{
	lobbyButton.Update();
}

void LobbyScene::Render(HDC hdc)
{
	lobbyButton.Render(hdc);
}