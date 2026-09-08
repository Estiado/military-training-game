#include "player.h"
#include "raylib.h"
#include "math.h"

Player::Player(Vector3 startPosition)
    : position(startPosition), velocity({0, 0, 0}), 
      speed(0.15f), sensitivity(0.003f)
{
    // Initialize camera
    camera.position = position;
    camera.target = Vector3Add(position, {0, 0, 1});
    camera.up = {0, 1, 0};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

Player::~Player()
{
}

void Player::Update()
{
    HandleInput();
    UpdateCamera();
}

void Player::HandleInput()
{
    Vector3 direction = {0, 0, 0};
    
    // Movement input (WASD)
    if (IsKeyDown(KEY_W))
    {
        direction.x += cosf(atan2f(camera.target.z - camera.position.z, 
                                    camera.target.x - camera.position.x));
        direction.z += sinf(atan2f(camera.target.z - camera.position.z, 
                                    camera.target.x - camera.position.x));
    }
    if (IsKeyDown(KEY_S))
    {
        direction.x -= cosf(atan2f(camera.target.z - camera.position.z, 
                                    camera.target.x - camera.position.x));
        direction.z -= sinf(atan2f(camera.target.z - camera.position.z, 
                                    camera.target.x - camera.position.x));
    }
    if (IsKeyDown(KEY_A))
    {
        direction.x -= cosf(atan2f(camera.target.z - camera.position.z, 
                                    camera.target.x - camera.position.x) + 1.5708f);
        direction.z -= sinf(atan2f(camera.target.z - camera.position.z, 
                                    camera.target.x - camera.position.x) + 1.5708f);
    }
    if (IsKeyDown(KEY_D))
    {
        direction.x += cosf(atan2f(camera.target.z - camera.position.z, 
                                    camera.target.x - camera.position.x) + 1.5708f);
        direction.z += sinf(atan2f(camera.target.z - camera.position.z, 
                                    camera.target.x - camera.position.x) + 1.5708f);
    }
    
    // Apply movement
    position.x += direction.x * speed;
    position.z += direction.z * speed;
    
    // Keep player above ground
    if (position.y < 2.0f) position.y = 2.0f;
}

void Player::UpdateCamera()
{
    camera.position = position;
    
    // Mouse look
    Vector2 mouseDelta = GetMouseDelta();
    
    Vector3 forward = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
    Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, camera.up));
    
    float angleY = -mouseDelta.x * sensitivity;
    float angleX = -mouseDelta.y * sensitivity;
    
    // Rotate forward vector
    forward = Vector3RotateByAxisAngle(forward, camera.up, angleY);
    forward = Vector3RotateByAxisAngle(forward, right, angleX);
    
    camera.target = Vector3Add(camera.position, Vector3Scale(forward, 1.0f));
}

Camera3D Player::GetCamera() const
{
    return camera;
}

Vector3 Player::GetPosition() const
{
    return position;
}