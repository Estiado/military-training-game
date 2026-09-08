# C++ and Raylib Learning Guide for Military Training Game

## Table of Contents
1. [C++ Basics](#c-basics)
2. [Object-Oriented Programming](#object-oriented-programming)
3. [Raylib Fundamentals](#raylib-fundamentals)
4. [Game Development Concepts](#game-development-concepts)

## C++ Basics

### Variables and Data Types
```cpp
int health = 100;           // Integer
float speed = 5.5f;         // Floating point
bool isAlive = true;        // Boolean
std::string name = "Player"; // String
```

### Functions
Functions are reusable blocks of code:

```cpp
// Function declaration
void PrintHealth(int health);

// Function definition
void PrintHealth(int health)
{
    printf("Health: %d\n", health);
}
```

### Control Flow
```cpp
// If statement
if (health > 0)
{
    // Player is alive
}
else
{
    // Player is dead
}

// Loops
for (int i = 0; i < 10; i++)
{
    printf("%d\n", i);
}

while (isAlive)
{
    // Game loop
}
```

## Object-Oriented Programming

### Classes
Classes are blueprints for objects. Our game uses several classes:

#### Player Class
```cpp
class Player
{
public:
    Player(Vector3 startPosition);  // Constructor
    ~Player();                      // Destructor
    
    void Update();                  // Member function
    Vector3 GetPosition() const;    // Const member function
    
private:
    Vector3 position;               // Member variable
    float speed;                    // Member variable
};
```

### Key Concepts

#### Encapsulation
- **Public:** Accessible from outside the class
- **Private:** Only accessible within the class
- **Protected:** Accessible by child classes

```cpp
class Soldier
{
public:      // Everyone can access
    void Salute();
    
private:     // Only Soldier class can access
    int stamina;
    float morale;
};
```

#### Inheritance
Create new classes based on existing ones:

```cpp
class Soldier : public Player  // Soldier inherits from Player
{
public:
    void FireWeapon();
    void DoFormation();
    
private:
    int ammunition;
};
```

#### Polymorphism
Same function name, different behavior:

```cpp
class Character  // Base class
{
public:
    virtual void Move() {}  // Virtual function
};

class Soldier : public Character
{
public:
    void Move() override  // Override base class function
    {
        // Different movement logic for Soldier
    }
};
```

## Raylib Fundamentals

### Initialization and Window Setup
```cpp
#include "raylib.h"

int main()
{
    // Create a window
    InitWindow(800, 600, "My Game");
    SetTargetFPS(60);  // Set 60 FPS
    
    // Main loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Draw your game here
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
```

### 3D Graphics

#### Camera and 3D Mode
```cpp
Camera3D camera = {{0, 10, 10}, {0, 0, 0}, {0, 1, 0}, 60, CAMERA_PERSPECTIVE};

BeginMode3D(camera);
    DrawCube({0, 0, 0}, 2, 2, 2, RED);
    DrawSphere({5, 0, 0}, 1, BLUE);
EndMode3D();
```

#### 3D Shapes
```cpp
DrawCube(position, width, height, length, color);
DrawSphere(center, radius, color);
DrawLine3D(startPos, endPos, color);
DrawModel(model, position, scale, color);
```

### Input Handling
```cpp
// Keyboard input
if (IsKeyDown(KEY_W))
{
    // W key is being held
}

if (IsKeyPressed(KEY_SPACE))
{
    // Space key was just pressed
}

// Mouse input
Vector2 mousePos = GetMousePosition();
Vector2 mouseDelta = GetMouseDelta();

if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
{
    // Left mouse button is being held
}
```

## Game Development Concepts

### Game Loop
The core of every game:

```cpp
while (!WindowShouldClose())
{
    // 1. UPDATE: Update game state
    player.Update();
    enemy.Update();
    
    // 2. DRAW: Render everything
    BeginDrawing();
    ClearBackground(RAYWHITE);
    player.Draw();
    enemy.Draw();
    EndDrawing();
}
```

### First-Person Camera

```cpp
// Store player position and rotation
Vector3 playerPos = {0, 2, 0};
float yaw = 0;      // Left/right rotation
float pitch = 0;    // Up/down rotation

// In update loop:
Vector2 mouseDelta = GetMouseDelta();
yaw -= mouseDelta.x * 0.003f;
pitch -= mouseDelta.y * 0.003f;

// Clamp pitch to prevent looking behind
if (pitch > 1.57f) pitch = 1.57f;      // 90 degrees
if (pitch < -1.57f) pitch = -1.57f;   // -90 degrees

// Calculate forward direction
Vector3 forward = {
    sinf(yaw) * cosf(pitch),
    sinf(pitch),
    cosf(yaw) * cosf(pitch)
};

// Update camera target
camera.target = Vector3Add(playerPos, forward);
```

### Game States

```cpp
enum GameState
{
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER
};

class Game
{
private:
    GameState currentState;
    
public:
    void Update()
    {
        switch (currentState)
        {
            case MENU:
                // Handle menu logic
                break;
            case PLAYING:
                // Update game
                break;
            case PAUSED:
                // Show pause screen
                break;
            case GAME_OVER:
                // Show game over screen
                break;
        }
    }
};
```

## Common Raylib Functions

### Drawing
```cpp
DrawText(text, x, y, fontSize, color);
DrawRectangle(x, y, width, height, color);
DrawCircle(centerX, centerY, radius, color);
DrawFPS(x, y);  // Show current FPS
```

### Colors
```cpp
RAYWHITE, RAYBLACK, RED, GREEN, BLUE, YELLOW, 
GRAY, DARKGREEN, LIGHTGRAY, SKYBLUE
```

### Vector Math (Very Important!)
```cpp
#include "raylib.h"

Vector3 a = {1, 2, 3};
Vector3 b = {4, 5, 6};

// Vector operations
Vector3 c = Vector3Add(a, b);           // Addition
Vector3 d = Vector3Subtract(a, b);      // Subtraction
Vector3 e = Vector3Scale(a, 2.0f);      // Scale
float len = Vector3Length(a);           // Length/magnitude
Vector3 norm = Vector3Normalize(a);     // Normalize to unit vector
float dot = Vector3DotProduct(a, b);    // Dot product
Vector3 cross = Vector3CrossProduct(a, b); // Cross product
```

## Next Steps

1. **Compile and run** the basic game
2. **Modify the Scene** to add more training ground elements
3. **Add NPC soldiers** as simple cubes (you'll create a Soldier class)
4. **Implement training tasks** (standing, marching, etc.)
5. **Add scoring system** based on performance

## Useful Resources

- [Raylib Website](https://www.raylib.com/)
- [Raylib Cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html)
- [C++ Reference](https://en.cppreference.com/)
- [Raylib Examples](https://www.raylib.com/examples.html)

## Common Mistakes to Avoid

1. **Not deleting dynamically allocated memory** - leads to memory leaks
2. **Forgetting to initialize variables** - can cause crashes
3. **Not handling input properly** - game controls feel unresponsive
4. **Magic numbers in code** - use named constants instead
5. **Inefficient loops** - can cause frame rate drops

## Tips for Learning

- **Read the code carefully** - understand what each line does
- **Experiment** - change values and see what happens
- **Start simple** - get the basics working before adding complexity
- **Test frequently** - compile and run often to catch errors early
- **Read compiler errors** - they usually tell you what's wrong
- **Use comments** - explain your code so you remember later
