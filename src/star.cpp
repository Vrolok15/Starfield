#include "star.h"
#include <raylib.h>

Star::Star() 
    : x(0)
    , y(0)
    , z(0)
    , speed(5)
    , radius(5) 
{
}

void Star::Init()
{
    x = GetRandomValue(0, GetScreenWidth());
    y = GetRandomValue(0, GetScreenHeight());
    z = GetScreenWidth();
}

void Star::Update() 
{
    z = z - speed;
    if (z < 1)
    {
        Init();
    }
}

float map(float value, float start1, float stop1, float start2, float stop2) {
    return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}

void Star::Draw() const
{
    float sx = map(float(x)/z, 0, 1, 0, GetScreenWidth());
    float sy = map(float(y)/z, 0, 1, 0, GetScreenHeight());
    DrawCircle(sx, sy, radius, WHITE);
}