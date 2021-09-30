#include "PatternDash.h"

PatternDash::PatternDash()
{
}

PatternDash::~PatternDash()
{
}

void PatternDash::Initialize()
{
    TransInfo.Position = Vector3(0.0f, 0.0f);
    TransInfo.Scale = Vector3(0.0f, 0.0f);

    
}

int PatternDash::Update(Transform& _rTransInfo)
{
   //RealObject->SetPosition(Vector3(_rTransInfo.Position.x-=10,_rTransInfo.Position.y));

    return 0;
}

void PatternDash::Render(HDC _hdc)
{
}

void PatternDash::Release()
{
}


