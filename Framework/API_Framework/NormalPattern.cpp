#include "NormalPattern.h"
#include "Object.h"

NormalPattern::NormalPattern()
{
}

NormalPattern::~NormalPattern()
{
}

void NormalPattern::Initialize()
{
    TransInfo.Scale = Vector3(16.0f, 12.0f);
    TransInfo.Position = Vector3(0.0f, 0.0f);

    Speed = 5.0f;

    RealObject->SetDamage(1);
    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetColliderScale(TransInfo.Scale);

    DrawKey = "EBullet";
}

int NormalPattern::Update(Transform& _rTransInfo)
{


	return 0;
}

void NormalPattern::Render(HDC _hdc)
{
}

void NormalPattern::Release()
{
}

