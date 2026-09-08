#include "game.h"
#include "raylib.h"

Game::Game(int width, int height)
    : screenWidth(width), screenHeight(height), gameState(1), 
      player(Vector3{0.0f, 2.0f, 4.0f}), scene()
{
}

Game::~Game()
{
}

void Game::Update()
{
    if (gameState == 1) // Playing
    {
        player.Update();
        scene.Update();
    }
    
    // Toggle pause with P key
    if (IsKeyPressed(KEY_P))
    {
        gameState = (gameState == 1) ? 2 : 1;
    }
}

void Game::Draw()
{
    // Begin 3D mode with player camera
    BeginMode3D(player.GetCamera());
    
    // Draw scene
    scene.Draw();
    
    EndMode3D();
    
    // Draw UI
    DrawFPS(10, 10);
    DrawText("Press P to pause", 10, 30, 20, BLACK);
    DrawText("WASD to move, Mouse to look", 10, 50, 20, BLACK);
    
    if (gameState == 2)
    {
        DrawText("PAUSED", screenWidth/2 - 50, screenHeight/2, 40, RED);
    }
}