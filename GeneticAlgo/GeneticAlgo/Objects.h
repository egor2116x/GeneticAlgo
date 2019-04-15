#pragma once
#include "Common.h"

class Object
{
public:
    Object(const ObjParams & params);
    virtual bool Move() = 0;
    virtual bool Action() = 0;
    virtual bool IsAlive() const { return m_Params.health > 0; }
    const ObjType & GetType() const { return m_Params.type; }
    virtual int GetValueObject() = 0;
    const Vector2ui & GetPosition() const { return m_Params.pos; }
    void SetPosition(const Vector2ui & pos) { m_Params.pos.x = pos.x; m_Params.pos.y = pos.y; }
    const ObjParams & GetParams() const { return m_Params; }
    virtual ~Object() {}
protected:
    ObjParams m_Params;
};

class Flower : public Object
{
public:
    Flower(const ObjParams & params) : Object(params) {}
    // Inherited via Object
    virtual bool Move() override;
    virtual bool Action() override;
    virtual int GetValueObject() override;
};

class Sheep : public Object
{
public:
    Sheep(const ObjParams & params) : Object(params) {}
    // Inherited via Object
    virtual bool Move() override;
    virtual bool Action() override;
    virtual int GetValueObject() override;
};

class Wolf : public Object
{
public:
    Wolf(const ObjParams & params) : Object(params) {}
    // Inherited via Object
    virtual bool Move() override;
    virtual bool Action() override;
    virtual int GetValueObject() override;
};
