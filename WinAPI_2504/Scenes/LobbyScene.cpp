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
	// �簢�� �׸���
}

void LobbyScene::TriggerEnterPlayButton()
{
	if (_playButton.left > mousePos.x || _playButton.right < mousePos.x)
		return;
	if (_playButton.top > mousePos.y || _playButton.bottom < mousePos.y)
		return;
	_isTriggerPlayButton = true;
	// ��ư �� �� �� ���ϰ�
}

void LobbyScene::TriggerExitPlayButton()
{
	if (_playButton.left <= mousePos.x || _playButton.right >= mousePos.x)
		return;
	if (_playButton.top <=mousePos.y || _playButton.bottom >= mousePos.y)
		return;
	_isTriggerPlayButton = false;
	// ��ư �� �������
}

void LobbyScene::ShowTitle()
{

}
