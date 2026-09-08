#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
public:
    Player(Vector3 startPosition);
    ~Player();
    
    void Update();
    Camera3D GetCamera() const;
    Vector3 GetPosition() const;
    
private:
    Vector3 position;
    Vector3 velocity;
    float speed;
    float sensitivity;
    
    Camera3D camera;
    
    void HandleInput();
    void UpdateCamera();
};

#endif