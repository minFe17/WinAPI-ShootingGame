#include "Framework.h"

ScoreManager::ScoreManager()
{
	score = 0;
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::AddScore(int score)
{
	score += score;
}
