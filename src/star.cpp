#include "star.h"

Star::Star(int offset) 
    : position({0, 0, 0})
    , speed(10)
    , radius(1)
    , offset(offset)
{
}

void Star::Init()
{
    position.x = GetRandomValue(-(GetScreenWidth()-offset*2), GetScreenWidth()-offset*2);
    position.y = GetRandomValue(-(GetScreenHeight()-offset*2), GetScreenHeight()-offset*2);
    position.z = GetRandomValue(0, GetScreenWidth());
    prevPos = position;
}

void Star::Update() 
{
    prevPos = position;  // Store current position before update
    position.z -= speed;
    if (position.z < 1)
    {
        Init();
    }
}

void Star::Draw() const
{
    Vector2 screenPos = {
        GetScreenWidth()/2.0f + (position.x / position.z) * (GetScreenWidth()-offset*2),
        GetScreenHeight()/2.0f + (position.y / position.z) * (GetScreenHeight()-offset*2)
    };
    
    Vector2 prevScreenPos = {
        GetScreenWidth()/2.0f + (prevPos.x / prevPos.z) * (GetScreenWidth()-offset*2),
        GetScreenHeight()/2.0f + (prevPos.y / prevPos.z) * (GetScreenHeight()-offset*2)
    };

    if (screenPos.x > offset && screenPos.x < GetScreenWidth()-offset &&
        screenPos.y > offset && screenPos.y < GetScreenHeight()-offset)
    {
        DrawLineEx(prevScreenPos, screenPos, 1.0f, WHITE);
        float r = radius * (GetScreenWidth() / position.z);
        DrawCircle(screenPos.x, screenPos.y, r, WHITE);
    }
}