#pragma once
#include "stdafx.h"

enum class ObjType { Sheep, Wolf, Flower, None };
const int g_ObjSpeedDefault = 1;
const int g_ObjHealthDefault = 1;
const unsigned WORLD_WIDTH = 90;
const unsigned WORLD_HEIGHT = 28;
const size_t flowersGenSize = 10;
const size_t SheepsGenSize = 10;
const size_t WolvesGenSize = 10;

struct Vector2ui
{
    Vector2ui(unsigned _x = 0, unsigned _y = 0) : x(_x), y(_y) {}
    unsigned x;
    unsigned y;
};

struct GenerationInfo
{
    int generation;                         // when born
    int steps;                              // how long alive
    int eat;                                // how lot of eats
    std::unique_ptr<GenerationInfo> parent; // parent
};

struct GenerationParams
{
    size_t generationSize;
    ObjType type;
};

struct ObjParams
{
    ObjType type;
    int speed;
    int health;
    GenerationInfo genInfo;
    Vector2ui pos;
};

