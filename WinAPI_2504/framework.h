#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define PI 3.141592f

#define DELTA Timer::Get()->GetElapsedTime()


#include <windows.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#include "Framework/Utilities/Singleton.h"
#include "Framework/Utilities/Timer.h"
#include "Framework/Utilities/Input.h"
#include "Framework/Manager/ScoreManager.h"

#include "Framework/Math/Vector2.h"

#include "Objects/ItemType.h"
#include "Objects/Circle.h"
//#include "Objects/Circle.h"
#include "Objects/PolygonVector.h"
#include "Objects/Player.h"
#include "Objects/Bullet.h"
#include "Objects/BulletManager.h"

#include "Objects/Enemy.h"
#include "Objects/Enemys/EnemyDodger.h"
#include "Objects/Enemys/EnemyBig.h"
#include "Objects/Enemys/EnemyGrunt.h"
#include "Objects/Enemys/EnemyKamikaze.h"
#include "Objects/Enemys/EnemyBossShip.h"
#include "Objects/EnemyManager.h"

#include "Objects/NormalPlayer.h"
#include "Objects/HeavyPlayer.h"
#include "Objects/HomingPlayer.h"
#include "Objects/Item.h"
#include "Objects/ItemManager.h"

#include "Framework/Manager/EnemyController.h"

#include "Scenes/Scene.h"
#include "Scenes/LobbyScene.h"
#include "Scenes/ChoiceCharacterScene.h"
#include "Scenes/ShootingScene.h"
#include "Scenes/GameOverScene.h"
#include "Scenes/GameClearScene.h"
#include "Framework/Manager/SceneManager.h"
#include "Framework/GameManager.h"

//constexpr COLORREF COLOR_PLAYER_NORMAL = RGB(255, 255, 150);
//constexpr COLORREF COLOR_PLAYER_POWERED = RGB(200, 150, 255);
//constexpr COLORREF COLOR_ENEMY_BULLET = RGB(255, 100, 50);

#define COLOR_PLAYER_NORMAL RGB(255, 255, 150)
#define COLOR_PLAYER_POWERED RGB(200, 150, 255)
#define COLOR_ENEMY_BULLET RGB(255, 100, 50)

extern HWND hWnd;
extern Vector2 mousePos;