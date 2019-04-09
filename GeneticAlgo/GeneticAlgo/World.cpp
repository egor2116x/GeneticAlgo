#include "World.h"

World World::m_Instance;

World::World() : m_Stop(false), m_Size({WORLD_WIDTH, WORLD_HEIGHT})
{
    std::srand(time(0));

    for (auto & obj : m_Objects)
    {
        obj->SetPosition({ std::rand() % WORLD_WIDTH + 1,
                           std::rand() % WORLD_HEIGHT + 1});
    }

    Draw();
}

void World::Update()
{
    for (auto it = m_Objects.begin(); it != m_Objects.end(); it++)
    {
        if ((*it)->IsAlive())
        {
            (*it)->Move();
            (*it)->Action();
        }
        else
        {
            m_Objects.erase(it);
        }
    }

    void Reproduce();
    void Selection();
}

void World::Draw()
{
}

void World::Run()
{
    while (!m_Stop)
    {
        Update();
        Draw();
        if (CheckSolution())
        {
            m_Stop = true;
        }
    }
}
