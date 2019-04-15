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
            throw std::logic_error("Unknown object type");
    }
}

void GeneticEngine::Reproduce()
{
    Object * obj = nullptr;

    // flowers
    auto values = GetObjectsByType(m_Objects, ObjType::Flower);
    std::sort(values->begin(), values->end(), [](const std::pair<size_t, int> &left, const std::pair<size_t, int> &right)-> bool { return left.second < right.second; });
    for (size_t i = values->size() - 1; i >= values->size() / 2; i--)
    {
        obj = Mutation(m_Objects[(*values)[i].first]);
        m_NewObjects.push_back(obj);
    }
    delete values;
    values = nullptr;

    // Sheeps
    values = GetObjectsByType(m_Objects, ObjType::Sheep);
    std::sort(values->begin(), values->end(), [](const std::pair<size_t, int> &left, const std::pair<size_t, int> &right)-> bool { return left.second < right.second; });
    for (size_t i = values->size() - 1; i >= values->size() / 2; i--)
    {
        obj = Mutation(m_Objects[(*values)[i].first]);
        m_NewObjects.push_back(obj);
    }
    delete values;
    values = nullptr;

    // Wolves
    values = GetObjectsByType(m_Objects, ObjType::Wolf);
    std::sort(values->begin(), values->end(), [](const std::pair<size_t, int> &left, const std::pair<size_t, int> &right)-> bool { return left.second < right.second; });
    for (size_t i = values->size() - 1; i >= values->size() / 2; i--)
    {
        obj = Mutation(m_Objects[(*values)[i].first]);
        m_NewObjects.push_back(obj);
    }
}

void GeneticEngine::Selection()
{
    auto values = GetObjectsByType(m_Objects, ObjType::Flower);
    size_t idx = -1;
    for (size_t i = 0; i < values->size() / 2; i++)
    {
        idx = rand() % values->size() + 1;
        m_NewObjects.push_back(m_Objects[(*values)[idx].first]);
    }
    delete values;
    values = nullptr;

    values = GetObjectsByType(m_Objects, ObjType::Sheep);
    idx = -1;
    for (size_t i = 0; i < values->size() / 2; i++)
    {
        idx = rand() % values->size() + 1;
        m_NewObjects.push_back(m_Objects[(*values)[idx].first]);
    }
    delete values;
    values = nullptr;

    values = GetObjectsByType(m_Objects, ObjType::Wolf);
    idx = -1;
    for (size_t i = 0; i < values->size() / 2; i++)
    {
        idx = rand() % values->size() + 1;
        m_NewObjects.push_back(m_Objects[(*values)[idx].first]);
    }

}

bool GeneticEngine::CheckSolution()
{
    // to do
    return false;
}

Object * GeneticEngine::Mutation(const Object * obj)
{
    const auto & pos = obj->GetPosition();
    const auto & params = obj->GetParams();

    std::unique_ptr<Object> newObject(nullptr);
    switch (obj->GetType())
    {
    case ObjType::Flower:
        // find free place for new object
        // copy params
        break;
    case ObjType::Sheep:
        // make mutation
        // copy other params
        break;
    case ObjType::Wolf:
        // make mutation
        // copy other params
        break;
    default:
        throw std::logic_error("Unknown object type");
    }

    return newObject.release();
}

std::vector<std::pair<size_t, int>> * GeneticEngine::GetObjectsByType(const std::vector<Object *> & objects, const ObjType & type)
{
    std::vector<std::pair<size_t, int>> * values = new std::vector<std::pair<size_t, int>>();
    for (size_t i = 0; i < objects.size(); i++)
    {
        if (m_Objects[i]->IsAlive() && m_Objects[i]->GetType() == type)
        {
            values->push_back(std::make_pair(i, objects[i]->GetValueObject()));
        }
    }

    return values;
}
