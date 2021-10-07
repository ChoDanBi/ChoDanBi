#pragma once
#include "Headers.h"

class ScoreManager
{
private:
	static ScoreManager* Instance;
public:
	static ScoreManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ScoreManager;

		return Instance;
	}
private:
	UINT Score;
	vector<int> NumberList;
	Bitmap* Image;
public:
	void Initialize();
	UINT GetScore() { return Score; }
	void SetScore(int _Score) { Score = _Score; }
	void SetImage(Bitmap* _Image) { Image = _Image; }

	vector<int>* GetScoreNumber() { return &NumberList; }

	void MakeScoreNumber();

	void Render(HDC _hdc);
};

