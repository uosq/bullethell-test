#include "entity.h"
#include "raylib.h"
#include "projectile.h"
#include "player.h"
#include <cmath>
#include <vector>

#define SPAWN_INTERVAL 0.1f

std::vector<Entity*> entitylist;

void UpdateEntities(float deltaTime);
void DrawEntities();
void EmptyList();

void CleanEntityList(Player *player);

int main(void) {
    InitWindow(800, 800, "Bullet Hell");
    SetTargetFPS(60);

    Projectile *proj = new Projectile(&entitylist);
    Player *player = new Player(&entitylist);

    proj->SetPosition(400, 90);
    proj->SetSize(40);

    double nextSpawnTime = 0;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        double time = GetTime();

        CleanEntityList(player);
        UpdateEntities(deltaTime);

        if (time >= nextSpawnTime) {
            nextSpawnTime = time + SPAWN_INTERVAL;

            int numBullets = GetRandomValue(3, 8); 

            float rotationSpeed = 1.5f; // radians/sec
            float baseAngle = rotationSpeed * time;

            for (int i = 0; i < numBullets; i++) {
                float randomOffset = GetRandomValue(0, 314) / 100.0f; // 0 to ~3.14 radians
                float angle = baseAngle + i * 2 * PI / numBullets + randomOffset;

                Projectile *bullet = new Projectile(&entitylist);
                Vector2 pos = proj->GetPosition();
                bullet->SetPosition(pos.x, pos.y);
                bullet->SetColor(RED);
                bullet->SetSize(GetRandomValue(4, 15));
                bullet->SetColor(ColorFromHSV(GetRandomValue(0, 360), 0.5f, 1.f));

                float speedMagnitude = GetRandomValue(80, 120);
                bullet->speed = { cos(angle) * speedMagnitude, sin(angle) * speedMagnitude };
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawEntities();

        DrawText(TextFormat("Colliding: %b", player->IsColliding(&entitylist)), 10, 10, 16, WHITE);
        DrawText(TextFormat("Entities: %i", entitylist.size()), 10, 50, 16, WHITE);
        DrawFPS(10, 70);

        EndDrawing();
    }

    EmptyList();
    CloseWindow();
    return 0;
}

void CleanEntityList(Player *player) {
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


void EmptyList() {
    for (int i = 0; i < entitylist.size(); i++) {
        Entity *entity = entitylist.at(i);
        if (!entity)
            continue;
        delete &entity;
    }

    entitylist.clear();
}

void DrawEntities() {
    for (int i = 0; i < entitylist.size(); i++) {
        Entity *base = entitylist.at(i);
        if (!base)
            continue;

        base->Draw();
    }
}

void UpdateEntities(float deltaTime) {
    for (int i = 0; i < entitylist.size(); i++) {
        Entity *entity = entitylist.at(i);
        if (!entity)
            continue;

        entity->Update(deltaTime);
    }
}