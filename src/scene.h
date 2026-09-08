#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"

class Scene
{
public:
    Scene();
    ~Scene();
    
    void Update();
    void Draw();
    
private:
    // Ground and basic geometry
    Mesh groundMesh;
    Model groundModel;
};

#endif