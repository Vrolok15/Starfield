#include <raylib.h>
#include "star.h"

int main() 
{
    
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    
    Star star;
    
    InitWindow(screenWidth, screenHeight, "STARFIELD C++");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        star.Update();
        
        BeginDrawing();
            ClearBackground(BLACK);
            star.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}