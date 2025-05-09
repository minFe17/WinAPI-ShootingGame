#include "Framework.h"

void LobbyScene::Update()
{
	TriggerEnterPlayButton();
	TriggerExitPlayButton();

	if (_isTriggerPlayButton && Input::Get()->IsKeyDown(VK_LBUTTON))
	{

	}
}

void LobbyScene::Render(HDC hdc)
{
	if (!_isShowUI)
	{
		SetPlayButton();
		ShowTitle();
	}
}

void LobbyScene::SetPlayButton()
{
	//_playButton = { left,top, right, bottom };
	// 사각형 그리기
}

void LobbyScene::TriggerEnterPlayButton()
{
	if (_playButton.left > mousePos.x || _playButton.right < mousePos.x)
		return;
	if (_playButton.top > mousePos.y || _playButton.bottom < mousePos.y)
		return;
	_isTriggerPlayButton = true;
	// 버튼 색 좀 더 진하게
}

void LobbyScene::TriggerExitPlayButton()
{
	if (_playButton.left <= mousePos.x || _playButton.right >= mousePos.x)
		return;
	if (_playButton.top <=mousePos.y || _playButton.bottom >= mousePos.y)
		return;
	_isTriggerPlayButton = false;
	// 버튼 색 원래대로
}

void LobbyScene::ShowTitle()
{

}
