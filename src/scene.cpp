#include "scene.h"
#include "raylib.h"

Scene::Scene()
{
    // Create a ground plane
    groundMesh = GenMeshPlane(100.0f, 100.0f, 10, 10);
    groundModel = LoadModelFromMesh(groundMesh);
    groundModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].color = DARKGREEN;
}

Scene::~Scene()
{
    UnloadModel(groundModel);
}

void Scene::Update()
{
    // Update scene logic here
}

void Scene::Draw()
{
    // Draw ground
    DrawModel(groundModel, Vector3Zero(), 1.0f, WHITE);
    
    // Draw some simple training ground markers
    // Draw grid lines
    for (int i = -50; i <= 50; i += 10)
    {
        DrawLine3D(
            {(float)i, 0.01f, -50.0f},
            {(float)i, 0.01f, 50.0f},
            GRAY
        );
        DrawLine3D(
            {-50.0f, 0.01f, (float)i},
            {50.0f, 0.01f, (float)i},
            GRAY
        );
    }
    
    // Draw some cubes as training obstacles
    for (int i = 0; i < 5; i++)
    {
        DrawCube({-20.0f + i * 10.0f, 1.0f, -20.0f}, 2.0f, 2.0f, 2.0f, RED);
    }
    
    // Draw sky
    DrawCube({0, 50, 0}, 200, 100, 200, SKYBLUE);
}