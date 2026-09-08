#include "raylib.h"
#include "game.h"

int main()
{
    // Initialize window
    const int screenWidth = 1280;
    const int screenHeight = 720;
    
    InitWindow(screenWidth, screenHeight, "Military Training Game (军训模拟器)");
    SetTargetFPS(60);
    
    // Create game instance
    Game game(screenWidth, screenHeight);
    
    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        game.Update();
        
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        game.Draw();
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}