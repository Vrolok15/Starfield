#include <raylib.h>
#include "star.h"

int main() 
{
    
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;
    
    Star stars[100];
    
    InitWindow(screenWidth, screenHeight, "STARFIELD C++");
    SetTargetFPS(60);
    
    // Initialize stars after window creation
    for (Star& star : stars)
    {
        star.Init();
    }
    
    while (!WindowShouldClose())
    {
        for (Star& star : stars)
        {
            star.Update();
        }
        
        BeginDrawing();
            ClearBackground(BLACK);
            for (Star& star : stars)
            {
                star.Draw();
            }
        EndDrawing();
    }
    
    CloseWindow();
}