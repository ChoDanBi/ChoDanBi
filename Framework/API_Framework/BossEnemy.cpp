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

    Frame = 1;
    Animation = ANIMATION::UPSWING;
    a_Time = GetTickCount64();

    Time = GetTickCount64();
    Skill = SKILL::WAIT;
    Move = MOVE::STAY;
    Tick = 0;

    TransInfo.Scale = Vector3(400.0f, 625.0f);
    TransInfo.Position = Vector3(0.0f,0.0f);

    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
    Image = (new Bitmap)->LoadBmp(L"../Resource/BossEnemy_1.bmp");

    Moveing = false;
    Event = true;
    Active = false;

    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetHitPoint(HitPoint);
    RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 150, TransInfo.Scale.y - 540));
    RealObject->SetActive(true);
}

int BossEnemy::Update(Transform& _rTransInfo)
{
    if (Event && RealObject->GetHitPoint() >= 0)
    {
        _rTransInfo.Position.x -= Speed;
        if (_rTransInfo.Position.x <= 1000)
        {
            _rTransInfo.Position.x = 1000;
            Event = false;
            Moveing = true;
            Active = true;
        }
        return 0;
    }

    if (RealObject->GetHitPoint() <= 0 && !Active)
    {
        Skill = SKILL::END;
        Pattern(Skill, _rTransInfo);
        MoveAnimation(Move, _rTransInfo);
        if (RealObject->GetPosition().y >= 900)
            return 1;
        return 0;
    }
    
    MoveAnimation(Move, _rTransInfo);

    if (a_Time + 200 < GetTickCount64())
    {
        a_Time = GetTickCount64();
        if (!Moveing)
            Frame = 1;
        else if (Moveing && Active)
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
    
    

        if (!Event&& Active)
        {
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

            Pattern(Skill, _rTransInfo);
            RealObject->SetColliderPosition(
                _rTransInfo.Position.x + 25, _rTransInfo.Position.y + 20);
        }

    return 0;
}

void BossEnemy::Render(HDC _hdc)
{
    if(RealObject->GetHitPoint() > 0)
    TransparentBlt(_hdc,
        int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
        int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
        int(RealObject->GetScale().x),
        int(RealObject->GetScale().y),
        ImageList[DrawKey]->GetMemDC(),
        int(RealObject->GetScale().x * Frame),
        0,
        int(RealObject->GetScale().x),
        int(RealObject->GetScale().y),
        RGB(255, 0, 255));

    else if (RealObject->GetHitPoint() <= 0 && !Active)
        TransparentBlt(_hdc,
            int(RealObject->GetPosition().x - (400 / 2)),
            int(RealObject->GetPosition().y - (625/ 2)),
            400,
            625,
            Image->GetMemDC(),
            0,
            0,
            400,
            625,
            RGB(255, 0, 255));

    TransparentBlt(_hdc,
        WindowsWidth / 2 - 450,
        50,
        900,
        50,
        ImageList["BossHitPoint2"]->GetMemDC(),
        0,
        0,
        900,
        50,
        RGB(255, 0, 255));
    

    TransparentBlt(_hdc,
        WindowsWidth / 2 - 450 + 86, 50,
        int(RealObject->GetHitPoint() * 8.14f),50,
        ImageList["BossHitPoint1"]->GetMemDC(),
        86, 0,
        int(RealObject->GetHitPoint() * 8.14f), 50,
        RGB(255, 0, 255));
    
}

void BossEnemy::Release()
{
}


void BossEnemy::Pattern(SKILL _Skill, Transform& _rTransInfo)
{
    switch (_Skill)
    {
    case SKILL::WAIT:
        break;

    case SKILL::ATTACK:
        if (_rTransInfo.Position.y >= 600)
        {
            CreateBullet(_rTransInfo);
            Move = MOVE::UP;
        }
        else if (_rTransInfo.Position.y == 350)
        {
            CreateBullet(_rTransInfo);
            if (Move == MOVE::DOWN)
            {
                Move = MOVE::STAY;
                _rTransInfo.Position.y = 360;
                Skill = SKILL::WAIT;
            }
        }
        else if (_rTransInfo.Position.y <= 200)
        {
            CreateBullet(_rTransInfo);
            Move = MOVE::DOWN;
        }
        break;

    case SKILL::DASH:
        Move = MOVE::FORWARD;
        Moveing = false;
        if (_rTransInfo.Position.x < -100)
        {
            _rTransInfo.Position = Vector3((float)1300, float(100 * (rand() % 5) + 100));
            Tick++;
            if (Tick == 3)
                _rTransInfo.Position.y = 350;
        }
        if (Tick == 3 && _rTransInfo.Position.x == 1000)
        {
            Move = MOVE::STAY;
            Skill = SKILL::WAIT;
            Moveing = true;
        }
        break;

    case SKILL::STRINGPATTERN:
        if (Move == MOVE::UP && _rTransInfo.Position.y <= 60)
            Move = MOVE::STAY;
        if (Move == MOVE::STAY)
        {
            _rTransInfo.Position = Vector3(300 * cosf(Tick) + 850, 300 * -sinf(Tick) + 360);
            Tick+= PI/90;
        }
        if (_rTransInfo.Position.y == 660 || _rTransInfo.Position.y == 60
            || _rTransInfo.Position.x == 1150)
            CreateBullet(_rTransInfo);

        if (Tick >= 4.5 * PI)
            Move = MOVE::DOWN;
        
        if (Move == MOVE::DOWN && _rTransInfo.Position.y >= 360)
        {
            _rTransInfo.Position = Vector3(1000.0f, 360.0f);
            Skill = SKILL::WAIT;
            Move = MOVE::STAY;
        }
        break;
    case SKILL::END:
        Move = MOVE::DOWN;
        Event = true;
        Moveing = false;
        break;
    default:
        break;
    }
}

void BossEnemy::CreateBullet(Transform& _rTransInfo)
{
    for (int i = 0; i < 5; i++)
    {
        EBulletList->push_back(CreateBullet<EnemyBullet>(i, _rTransInfo));
    }
}

void BossEnemy::MoveAnimation(MOVE _Move, Transform& _rTransInfo)
{
    switch (_Move)
    {
    case MOVE::UP:
        _rTransInfo.Position.y -= Speed;
        break;
    case MOVE::DOWN:
        _rTransInfo.Position.y += Speed;
        break;
    case MOVE::BACK:
        _rTransInfo.Position.x += Speed;
        break;
    case MOVE::FORWARD:
        _rTransInfo.Position.x -= 15;
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
Object* BossEnemy::CreateBullet(int _Pattern, Transform& _rTransInfo)
{
    Bridge* pBridge = new T;

    Object* pBullet = ObjectFactory<Bullet>::CreateObject(_rTransInfo.Position, pBridge, _Pattern);

    return pBullet;
}