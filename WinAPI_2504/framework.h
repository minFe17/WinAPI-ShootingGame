﻿#pragma once

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

#include "Objects/PaintTool.h"
#include "Objects/Circle.h"
#include "Objects/Player.h"
#include "Objects/Bullet.h"
#include "Objects/BulletManager.h"
#include "Objects/Enemy.h"
#include "Framework/Manager/EnemyManager.h"

#include "Scenes/Scene.h"
#include "Scenes/LobbyScene.h"
#include "Scenes/ChoiceCharacterScene.h"
#include "Scenes/ShootingScene.h"
#include "Framework/Manager/SceneManager.h"
#include "Framework/GameManager.h"

extern HWND hWnd;
extern Vector2 mousePos;