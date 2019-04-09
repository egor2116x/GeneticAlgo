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
protected:
    std::list<Object *> m_Objects;
    std::list<Object *> m_NewObjects;
};

