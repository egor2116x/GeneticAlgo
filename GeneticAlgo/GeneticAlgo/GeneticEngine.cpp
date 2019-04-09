#include "GeneticEngine.h"

GeneticEngine::~GeneticEngine()
{
    for (auto & obj : m_Objects)
    {
        delete obj;
    }
}

void GeneticEngine::CreateGeniration(const GenerationParams & params)
{
    ObjParams objParams;
    unsigned x = 0;
    unsigned y = 0;
    switch (params.type)
    {
        case ObjType::Flower:
            // init of the first generation 
            objParams.health = g_ObjHealthDefault;
            objParams.speed = 0;
            objParams.type = ObjType::Flower;
            objParams.genInfo.eat = 0;
            objParams.genInfo.generation = 0;
            objParams.genInfo.steps = 0;
            objParams.genInfo.parent.reset(nullptr); 
            
            for (size_t i = 0; i < params.generationSize; i++)
            {
                x = std::rand() % WORLD_WIDTH;
                y = std::rand() % WORLD_HEIGHT;
                objParams.pos.x = (x == 0 ? 2 : (x == WORLD_WIDTH - 1) ? WORLD_WIDTH - 2 : x);
                objParams.pos.y = (y == 0 ? 2 : (y == WORLD_HEIGHT - 1) ? WORLD_HEIGHT - 2 : y);
                m_Objects.push_back(new Flower(objParams));
            }
            break;
        case ObjType::Sheep:

            objParams.health = g_ObjHealthDefault;
            objParams.speed = g_ObjSpeedDefault;
            objParams.type = ObjType::Sheep;
            objParams.genInfo.eat = 0;
            objParams.genInfo.generation = 0;
            objParams.genInfo.steps = 0;
            objParams.genInfo.parent.reset(nullptr);

            for (size_t i = 0; i < params.generationSize; i++)
            {
                x = std::rand() % WORLD_WIDTH;
                y = std::rand() % WORLD_HEIGHT;
                objParams.pos.x = (x == 0 ? 2 : (x == WORLD_WIDTH - 1) ? WORLD_WIDTH - 2 : x);
                objParams.pos.y = (y == 0 ? 2 : (y == WORLD_HEIGHT - 1) ? WORLD_HEIGHT - 2 : y);
                m_Objects.push_back(new Sheep(objParams));
            }
            break;
        case ObjType::Wolf:

            objParams.health = g_ObjHealthDefault;
            objParams.speed = g_ObjSpeedDefault;
            objParams.type = ObjType::Wolf;
            objParams.genInfo.eat = 0;
            objParams.genInfo.generation = 0;
            objParams.genInfo.steps = 0;
            objParams.genInfo.parent.reset(nullptr);

            for (size_t i = 0; i < params.generationSize; i++)
            {
                x = std::rand() % WORLD_WIDTH;
                y = std::rand() % WORLD_HEIGHT;
                objParams.pos.x = (x == 0 ? 2 : (x == WORLD_WIDTH - 1) ? WORLD_WIDTH - 2 : x);
                objParams.pos.y = (y == 0 ? 2 : (y == WORLD_HEIGHT - 1) ? WORLD_HEIGHT - 2 : y);
                m_Objects.push_back(new Wolf(objParams));
            }
            break;
        default:
            throw L"Unknown object type";
    }
}

void GeneticEngine::Reproduce()
{
    //Mutation();
}

void GeneticEngine::Selection()
{
}

bool GeneticEngine::CheckSolution()
{
    return false;
}

Object * GeneticEngine::Mutation(const Object * obj)
{
    std::unique_ptr<Object> newObject(nullptr);
    switch (obj->GetType())
    {
    case ObjType::Flower:
        // they have no any mutation
        break;
    case ObjType::Sheep:

        break;
    case ObjType::Wolf:

        break;
    default:
        return nullptr;
    }

    return newObject.release();
}