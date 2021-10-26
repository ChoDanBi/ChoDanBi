#include "BossEnemy.h"
//#include "NormalEnemy.h"

#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bullet.h"
#include "EnemyBullet.h"


BossEnemy::BossEnemy()
{
}

BossEnemy::~BossEnemy()
{
}

void BossEnemy::Initialize()
{
    DrawKey = "BossEnemy";

    Speed = 10;
    HitPoint = 100;

    Frame = 0;
    Animation = ANIMATION::UPSWING;
    a_Time = GetTickCount64();

    Time = GetTickCount64();
    Skill = SKILL::WAIT;
    Move = MOVE::STAY;
    Tick = 0;

    TransInfo.Scale = Vector3(400.0f, 625.0f);
    TransInfo.Position = Vector3(0.0f,0.0f);

    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetHitPoint(HitPoint);
    RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 150, TransInfo.Scale.y - 540));


    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}

int BossEnemy::Update(Transform& _rTransInfo)
{
    if (a_Time + 200 < GetTickCount64())
    {
        a_Time = GetTickCount64();
        switch (Animation)
        {
        case ANIMATION::UPSWING:
            if (Frame <= 1)
                Animation = ANIMATION::DOWNSWING;
            Frame--;
            break;
        case ANIMATION::DOWNSWING:
            if (Frame >= 1)
                Animation = ANIMATION::UPSWING;
            Frame++;
            break;
        }  
    }
    /*

    if (Time + 3000 < GetTickCount64() && Skill == SKILL::WAIT)
    {
        Time = GetTickCount64();
        int i = rand() % 3 + 1;
        switch (i)
        {
        case 1:
            Skill = SKILL::ATTACK;
            Move = MOVE::DOWN;
            break;
        case 2:
            Skill = SKILL::DASH;
            break;
        case 3:
            Skill = SKILL::STRINGPATTERN;
            Move = MOVE::UP;
            break;
        }
        Tick = 0.0f;
    }
    else if (Time + 3000 < GetTickCount64() && Skill != SKILL::WAIT)
        Time = GetTickCount64();

    MoveAnimation(Move);
    Pattern(Skill);
    */

    RealObject->SetColliderPosition(
        TransInfo.Position.x + 25, TransInfo.Position.y + 20);

    return 0;
}

void BossEnemy::Render(HDC _hdc)
{
    TransparentBlt(_hdc,
        int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
        int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
        int(TransInfo.Scale.x),
        int(TransInfo.Scale.y),
        ImageList[DrawKey]->GetMemDC(),
        int(TransInfo.Scale.x * Frame),
        0,
        int(TransInfo.Scale.x),
        int(TransInfo.Scale.y),
        RGB(255, 0, 255));

    TransparentBlt(_hdc,
        WindowsWidth/2 - 450,
        50,
        900,
        50,
        ImageList["BossHitPoint1"]->GetMemDC(),
        0,
        0,
        900,
        50,
        RGB(255, 0, 255));

    TransparentBlt(_hdc,
        WindowsWidth / 2 - 450,
        50,
        900,
        50,
        ImageList["BossHitPoint2"]->GetMemDC(),
        0,
        0,
        int(86 + (HitPoint * 8.14f)),
        50,
        RGB(255, 0, 255));
}

void BossEnemy::Release()
{
}


void BossEnemy::Pattern(SKILL _Skill)
{
    switch (_Skill)
    {
    case SKILL::WAIT:
        break;
    case SKILL::ATTACK:
        if (TransInfo.Position.y >= 600)
        {
            CreateBullet();
            Move = MOVE::UP;
        }
        else if (TransInfo.Position.y == 350)
        {
            CreateBullet();
            if (Move == MOVE::DOWN)
            {
                Move = MOVE::STAY;
                TransInfo.Position.y = 360;
                Skill = SKILL::WAIT;
            }
        }
        else if (TransInfo.Position.y <= 200)
        {
            CreateBullet();
            Move = MOVE::DOWN;
        }
        break;
    case SKILL::DASH:
        Move = MOVE::FORWARD;
        if (TransInfo.Position.x < -100)
        {
            TransInfo.Position = Vector3((float)1300, float(100 * (rand() % 5) + 100));
            Tick++;
            if (Tick == 3)
                TransInfo.Position.y = 350;
        }
        if (Tick == 3 && TransInfo.Position.x == 1000)
        {
            Move = MOVE::STAY;
            Skill = SKILL::WAIT;
        }
        break;
    case SKILL::STRINGPATTERN:
        if (Move == MOVE::UP && TransInfo.Position.y <= 60)
            Move = MOVE::STAY;
        if (Move == MOVE::STAY)
        {
            TransInfo.Position = Vector3(300 * cosf(Tick) + 850, 300 * -sinf(Tick) + 360);
            Tick+= PI/90;
        }
        if (TransInfo.Position.y == 660 || TransInfo.Position.y == 60
            || TransInfo.Position.x == 1150)
            CreateBullet();

        if (Tick >= 4.5 * PI)
            Move = MOVE::DOWN;
        
        if (Move == MOVE::DOWN && TransInfo.Position.y >= 360)
        {
            TransInfo.Position = Vector3(1000.0f, 360.0f);
            Skill = SKILL::WAIT;
            Move = MOVE::STAY;
        }
        break;
    case SKILL::THREEPATTERN:
        Tick++;
        if (Tick == 5)
            Skill = SKILL::WAIT;

        break;
    default:
        break;
    }
}

void BossEnemy::CreateBullet()
{
    for (int i = 0; i < 5; i++)
    {
        EBulletList->push_back(CreateBullet<EnemyBullet>(i));
    }
}

void BossEnemy::MoveAnimation(MOVE _Move)
{
    switch (_Move)
    {
    case MOVE::UP:
        TransInfo.Position.y -= Speed;
        break;
    case MOVE::DOWN:
        TransInfo.Position.y += Speed;
        break;
    case MOVE::BACK:
        TransInfo.Position.x += Speed;
        break;
    case MOVE::FORWARD:
        TransInfo.Position.x -= Speed;
        break;
    case MOVE::STAY:
        break;
    default:
        break;
    }
    RealObject->SetColliderPosition(
        TransInfo.Position.x + 25, TransInfo.Position.y + 20);
}

template<typename T>
Object* BossEnemy::CreateBullet(int _Pattern)
{
    Bridge* pBridge = new T;

    Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge, _Pattern);

    return pBullet;
}