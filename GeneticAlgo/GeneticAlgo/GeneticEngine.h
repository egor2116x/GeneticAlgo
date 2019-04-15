#pragma once
#include "Objects.h"

class GeneticEngine
{
public:
    virtual ~GeneticEngine();
    void CreateGeniration(const GenerationParams & params);
protected:   
    void Reproduce();
    void Selection();
    bool CheckSolution();
    Object * Mutation(const Object * const obj);
    std::vector<std::pair<size_t, int>> * GetObjectsByType(const std::vector<Object *> & objects, const ObjType & type);
protected:
    std::vector<Object *> m_Objects;
    std::vector<Object *> m_NewObjects;
};

