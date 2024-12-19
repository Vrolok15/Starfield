#include "star.h"

Star::Star() 
    : position({0, 0, 0})
    , speed(10)
    , radius(1) 
{
}

void Star::Init()
{
    position.x = GetRandomValue(-(GetScreenWidth()-120), GetScreenWidth()-120);
    position.y = GetRandomValue(-(GetScreenHeight()-120), GetScreenHeight()-120);
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
        GetScreenWidth()/2.0f + (position.x / position.z) * (GetScreenWidth()-120),
        GetScreenHeight()/2.0f + (position.y / position.z) * (GetScreenHeight()-120)
    };
    
    Vector2 prevScreenPos = {
        GetScreenWidth()/2.0f + (prevPos.x / prevPos.z) * (GetScreenWidth()-120),
        GetScreenHeight()/2.0f + (prevPos.y / prevPos.z) * (GetScreenHeight()-120)
    };

    if (screenPos.x > 60 && screenPos.x < GetScreenWidth()-60 &&
        screenPos.y > 60 && screenPos.y < GetScreenHeight()-60)
    {
        DrawLineEx(prevScreenPos, screenPos, 1.0f, WHITE);
        float r = radius * (GetScreenWidth() / position.z);
        DrawCircle(screenPos.x, screenPos.y, r, WHITE);
    }
}