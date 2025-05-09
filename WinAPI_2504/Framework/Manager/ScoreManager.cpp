#include "Framework.h"

ScoreManager::ScoreManager()
{
	_score = 0;
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::AddScore(int score)
{
	_score += score;
}
