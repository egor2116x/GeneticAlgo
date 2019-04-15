#include "World.h"

World World::m_Instance;

World::World() : m_Stop(false), m_Size({WORLD_WIDTH, WORLD_HEIGHT}), m_Steps(0)
{
    std::srand(time(0));
    m_Map.resize(WORLD_HEIGHT);
    for (auto & row : m_Map)
    {
        row.resize(WORLD_WIDTH);
    }

    for (size_t j = 0; j < WORLD_HEIGHT; j++)
    {
        for (size_t i = 0; i < WORLD_WIDTH; i++)
        {
            if ((j == 0 || j == WORLD_HEIGHT - 1) ||
                (i == 0 || i == WORLD_WIDTH - 1))
            {
                m_Map[j][i] = '*';
            }
            
        }
    }

    Draw();
}

void World::Update()
{
    unsigned x = 0;
    unsigned y = 0;
    for (auto & obj : m_Objects)
    {
        x = obj->GetPosition().x;
        y = obj->GetPosition().y;
        switch (obj->GetType())
        {
        case ObjType::Flower:
            m_Map[y][x] = 'F';
            break;
        case ObjType::Sheep:
            m_Map[y][x] = 'S';
            break;
        case ObjType::Wolf:
            m_Map[y][x] = 'W';
            break;
        case ObjType::None:
            throw std::logic_error("Unknown object type");
        }
    }

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

    if (m_Steps % m_MaxStepsForCreateNewGen == 0)
    {
        Reproduce();
        Selection();
    }
}

void World::Draw()
{
    for (const auto & row : m_Map)
    {
        for (const auto & cell : row)
        {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
    std::cin.get();
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
