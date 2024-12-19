#include <raylib.h>
#include "star.h"
#include <vector>
#include <algorithm>

int main() 
{
    
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 800;
    constexpr int starCount = 400;
    constexpr int minSpeed = 5;
    constexpr int maxSpeed = 50;
    
    int speed = 10;
    int offset = 60;
    
    std::vector<Star> stars(starCount, Star(offset));
    
    InitWindow(screenWidth, screenHeight, "STARFIELD C++");
    SetTargetFPS(60);
    
    // Initialize stars after window creation
    for (Star& star : stars)
    {
        star.Init();
    }
    
    while (!WindowShouldClose())
    {
        // Handle speed changes with mouse wheel
        int wheel = GetMouseWheelMove();
        if (wheel != 0) {
            speed = std::min(maxSpeed, std::max(minSpeed, speed + wheel * 5));
            for (Star& star : stars) {
                star.SetSpeed(speed);
            }
        }
        
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