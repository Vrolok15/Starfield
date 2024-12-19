#include "star.h"
#include <raylib.h>
#include <cmath>

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

    // Calculate distance from center of screen
    float centerX = GetScreenWidth()/2.0f;
    float centerY = GetScreenHeight()/2.0f;
    float distFromCenter = sqrt(pow(screenPos.x - centerX, 2) + pow(screenPos.y - centerY, 2));

    // Only draw if star is within border AND not too close to center
    if (screenPos.x > offset && screenPos.x < GetScreenWidth()-offset &&
        screenPos.y > offset && screenPos.y < GetScreenHeight()-offset &&
        distFromCenter > 100)  // Adjust this value to change the size of the empty center
    {
        float r = radius * (GetScreenWidth() / position.z) / 2;
        DrawLineEx(prevScreenPos, screenPos, r, WHITE);
    }
}

void Star::SetSpeed(int newSpeed) {
    speed = newSpeed;
}