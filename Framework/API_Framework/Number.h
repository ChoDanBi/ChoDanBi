#pragma once
#include "Headers.h"

class Number
{
private:
	UINT Score;
	vector<int> NumberList;
	Bitmap* Image;
	Transform TransInfo;
public:
	void Initialize(Vector3 _vPos, int _Number);
	UINT GetScore() { return Score; }
	void SetScore(int _Score) { Score = _Score; }
	void SetImage(Bitmap* _Image) { Image = _Image; }

	vector<int>* GetScoreNumber() { return &NumberList; }

	void MakeScoreNumber(int _Number);
	void SetPosition(Vector3 _vPos) { TransInfo.Position = _vPos; }

	void Render(HDC _hdc);
};

