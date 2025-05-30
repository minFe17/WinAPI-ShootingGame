#pragma once

class ScoreManager : public Singleton<ScoreManager>
{
public:
	ScoreManager();
	~ScoreManager();
	void AddScore(int score);
	int GetScore() { return _score; }

private:
	int _score;
};