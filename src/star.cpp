#include "star.h"
#include <raylib.h>

Star::Star() 
    : x(0)
    , y(0)
    , speed(5)
    , radius(5) 
{
}

void Star::Init()
{
    x = GetRandomValue(0, GetScreenWidth());
    y = GetRandomValue(0, GetScreenHeight());
}

void Star::Update() 
{
    //add logic for drawing star path
}

void Star::Draw() const
{
    DrawCircle(x, y, radius, WHITE);
}