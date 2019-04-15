// GeneticAlgo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "World.h"


int main()
{
    try
    {
        auto & world = World::GetInstance();

        GenerationParams flowerParams;
        flowerParams.type = ObjType::Flower;
        flowerParams.generationSize = flowersGenSize;

        GenerationParams SheepParams;
        SheepParams.type = ObjType::Sheep;
        SheepParams.generationSize = SheepsGenSize;

        GenerationParams WolfParams;
        WolfParams.type = ObjType::Wolf;
        WolfParams.generationSize = WolvesGenSize;

        world.CreateGeniration(flowerParams);
        world.CreateGeniration(SheepParams);
        world.CreateGeniration(WolfParams);

        world.Run();
    }
    catch (std::runtime_error & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (std::logic_error & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cin.get();
    return 0;
}

