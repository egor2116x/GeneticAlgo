#include "Objects.h"

Object::Object(const ObjParams & params)
{
    m_Params.health = params.health;
    m_Params.speed = params.speed;
    m_Params.type = params.type;
    m_Params.genInfo.eat = params.genInfo.eat;
    m_Params.genInfo.generation = params.genInfo.generation;
    m_Params.genInfo.steps = params.genInfo.steps;
    m_Params.pos.x = params.pos.x;
    m_Params.pos.y = params.pos.y;
    
    if (params.genInfo.parent.get() != nullptr)
    {
        std::unique_ptr<GenerationInfo> parentInfo;
        parentInfo->eat = params.genInfo.parent->eat;
        parentInfo->generation = params.genInfo.parent->generation;
        parentInfo->steps = params.genInfo.parent->steps;

        m_Params.genInfo.parent.reset(parentInfo.release());
    }
}

bool Sheep::Move()
{
    return false;
}

bool Sheep::Action()
{
    return false;
}

int Sheep::GetValueObject()
{
    return 0;
}

bool Wolf::Move()
{
    return false;
}

bool Wolf::Action()
{
    return false;
}

int Wolf::GetValueObject()
{
    return 0;
}

bool Flower::Move()
{
    // they can't move
    return false;
}

bool Flower::Action()
{
    // they have no any actions
    return false;
}

int Flower::GetValueObject()
{
    return 0;
}
