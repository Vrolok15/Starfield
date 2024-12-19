#include <raylib.h>
#include "star.h"

int main() 
{
    
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;
    constexpr int starCount = 800;
    int speed = 10;
int offset = 60;
    
    Star stars[starCount];
    
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
            DrawRectangleLinesEx(Rectangle{(float)offset, (float)offset, (float)screenWidth-offset*2, (float)screenHeight-offset*2}, 5, WHITE);
            DrawText("STARFIELD", offset - 5, 20, 40, WHITE);
            DrawText(TextFormat("Speed: %i", speed), offset - 5, screenHeight - offset, 40, WHITE);
            for (Star& star : stars)
            {
                star.Draw();
            }
        EndDrawing();
    }
    
    CloseWindow();
}