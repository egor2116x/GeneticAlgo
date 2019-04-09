#pragma once
#include "GeneticEngine.h"

class World : public GeneticEngine
{
public:
    static World & GetInstance() { return m_Instance; }
    void Run();
private:
    World();
    void Update();
    void Draw();
private:
    static World m_Instance;
    bool m_Stop;
    Vector2ui m_Size;
    std::vector<std::vector<char>> m_Map;
};

