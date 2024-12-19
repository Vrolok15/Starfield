#include "star.h"

Star::Star() 
    : position({0, 0, 0})
    , speed(5)
    , radius(5) 
{
}

void Star::Init()
{
    position.x = GetRandomValue(-GetScreenWidth(), GetScreenWidth());
    position.y = GetRandomValue(-GetScreenHeight(), GetScreenHeight());
    position.z = GetRandomValue(0, GetScreenWidth());
}

void Star::Update() 
{
    position.z -= speed;
    if (position.z < 1)
    {
        Init();
    }
}

void Star::Draw() const
{
    // Project 3D position to 2D screen space
    Vector2 screenPos = {
        GetScreenWidth()/2.0f + (position.x / position.z) * GetScreenWidth(),
        GetScreenHeight()/2.0f + (position.y / position.z) * GetScreenHeight()
    };
    
    DrawCircle(screenPos.x, screenPos.y, radius, WHITE);
}