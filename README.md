# Military Training Game (军训模拟器)

A first-person perspective game simulating Chinese university military training (军训), built with C++ and Raylib.

## Project Overview

This game simulates the experience of military training (军训) that Chinese university students undergo. You control a soldier in first-person perspective, completing various training tasks like:
- Standing at attention
- Marching in formation
- Following commands
- Training drills

## Technology Stack

- **Language:** C++ (Modern C++11 and above)
- **Graphics Library:** Raylib (https://www.raylib.com/)
- **Platform:** Cross-platform (Windows, macOS, Linux)

## Prerequisites

- C++ compiler (GCC, Clang, or MSVC)
- Raylib library installed
- CMake (for building)

## Installation & Setup

### 1. Install Raylib

**Windows (MSVC):**
```bash
# Install vcpkg if you don't have it
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\vcpkg integrate install
.\vcpkg install raylib:x64-windows
```

**macOS (Homebrew):**
```bash
brew install raylib
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get install libraylib-dev
```

### 2. Clone and Build

```bash
git clone https://github.com/Estiado/military-training-game.git
cd military-training-game
mkdir build
cd build
cmake ..
make
```

### 3. Run

```bash
./military_training_game
```

## Project Structure

```
military-training-game/
├── src/
│   ├── main.cpp              # Entry point
│   ├── game.h                # Game class header
│   ├── game.cpp              # Game class implementation
│   ├── player.h              # Player class (first-person camera)
│   ├── player.cpp
│   ├── scene.h               # Training scene/environment
│   ├── scene.cpp
│   └── training_tasks.h      # Military training tasks
├── CMakeLists.txt            # Build configuration
├── README.md                 # This file
└── docs/
    └── learning_guide.md     # C++ & Raylib learning guide
```

## Learning Path

This project is designed to teach you:

1. **C++ Fundamentals**
   - Classes and objects
   - Memory management
   - Pointers and references
   - File I/O

2. **Game Development Concepts**
   - Game loops
   - Input handling
   - 3D graphics and camera systems
   - Collision detection
   - Game state management

3. **Raylib Specifics**
   - 3D rendering
   - Camera control
   - Model loading
   - Audio and input

## Roadmap

- [ ] Phase 1: Basic 3D scene and first-person camera
- [ ] Phase 2: Player movement and controls
- [ ] Phase 3: Training ground environment
- [ ] Phase 4: Simple training tasks (standing, marching)
- [ ] Phase 5: NPC soldiers and formations
- [ ] Phase 6: Training scenarios and scoring system
- [ ] Phase 7: Sound effects and UI

## Resources

- [Raylib Official Guide](https://www.raylib.com/)
- [Raylib Cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html)
- [C++ Learning Resources](./docs/learning_guide.md)
- [Raylib Examples](https://www.raylib.com/examples.html)

## Controls (To Be Implemented)

- **W/A/S/D** - Move forward/left/backward/right
- **Mouse** - Look around
- **SPACE** - Jump
- **ESC** - Exit game

## License

MIT License

## Author

Created by Estiado for learning C++ and game development