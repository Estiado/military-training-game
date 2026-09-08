#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "player.h"
#include "scene.h"

class Game
{
public:
    Game(int screenWidth, int screenHeight);
    ~Game();
    
    void Update();
    void Draw();
    
private:
    int screenWidth;
    int screenHeight;
    Player player;
    Scene scene;
    
    // Game state
    int gameState; // 0 = menu, 1 = playing, 2 = paused
};

#endif