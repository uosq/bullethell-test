#include "enemy.h"
#include "entity.h"
#include "entitymanager.h"
#include "raylib.h"
#include "player.h"
#include "collision.h"
#include <cmath>
#include <vector>

#define SPAWN_INTERVAL 0.1f

void EmptyList(std::vector<Entity*>& entitylist);
void CleanEntityList(Player *player, std::vector<Entity*>& entitylist);

int main(void) {
    InitWindow(800, 800, "Bullet Hell");
    SetTargetFPS(999);

    EntityManager *entityManager = new EntityManager();
    Collision *collision = new Collision();

    Enemy *enemy = new Enemy(entityManager);
    enemy->SetBulletNumber(10);
    enemy->SetPosition(400, 60);
    enemy->SetSize(40);

    Player *player = new Player();
    player->SetPosition(400, 600);

    entityManager->Add(player);
    entityManager->Add(enemy);

    std::vector<Entity*>& entitylist = entityManager->entitylist;

    double nextSpawnTime = 0;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        double time = GetTime();

        CleanEntityList(player, entitylist);
        entityManager->UpdateAll(deltaTime);

        BeginDrawing();
        ClearBackground(BLACK);
        
        entityManager->DrawAll();

        DrawText(TextFormat("Colliding: %b", collision->IsCollidingWithAny(player, entitylist)), 10, 10, 16, WHITE);
        DrawText(TextFormat("Entities: %i", entitylist.size()), 10, 50, 16, WHITE);
        DrawFPS(10, 70);

        EndDrawing();
    }

    delete collision;
    delete entityManager;

    EmptyList(entitylist);
    CloseWindow();
    return 0;
}

void CleanEntityList(Player *player, std::vector<Entity*>& entitylist) {
    for (int i = entitylist.size() - 1; i >= 0; i--) {
        Entity *entity = entitylist[i];
        if (entity == player)
            continue;

        if (!entity) {
            entitylist.erase(entitylist.begin() + i);
            continue;
        }

        Vector2 pos = entity->GetPosition();
        if (pos.x < 0 || pos.x > GetScreenWidth() || pos.y < 0 || pos.y > GetScreenHeight()) {
            delete entity;
            entitylist.erase(entitylist.begin() + i);
        }
    }
}

void EmptyList(std::vector<Entity*>& entitylist) {
    for (int i = 0; i < entitylist.size(); i++) {
        Entity *entity = entitylist.at(i);
        if (!entity)
            continue;
        delete entity;
    }

    entitylist.clear();
}