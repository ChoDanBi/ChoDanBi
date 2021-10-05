#pragma once
#include "Object.h"

class StageResult:public Object
{
private:
	bool Clear;
	Transform Buttom[2];

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new StageResult(*this); }

public:
	bool GetClear() { return Clear; }
	void SetClear(bool _Clear) { Clear = _Clear; }

public:
	StageResult();
	StageResult(const Transform& _rTransInfo): Object(_rTransInfo) {}
	virtual ~StageResult();
};

