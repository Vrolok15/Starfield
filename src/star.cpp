#include "star.h"
#include <raylib.h>

Star::Star() 
    : x(GetRandomValue(0, GetScreenWidth()))
    , y(GetRandomValue(0, GetScreenHeight()))
    , speed(5)
    , radius(15) 
{
}

void Star::Update() 
{
    //add logic for drawing star path
}

void Star::Draw() const
{
    DrawCircle(x, y, radius, WHITE);
}