#include "player.h"
#include "entity.h"
#include <raylib.h>

void Player::Update(float deltaTime) {
    Vector2 vel = {0, 0};

    if (IsKeyDown(KEY_W))
        vel.y += -1;
    if (IsKeyDown(KEY_S))
        vel.y += 1;
    if (IsKeyDown(KEY_D))
        vel.x += 1;
    if (IsKeyDown(KEY_A))
        vel.x += -1;

    float length = Vector2Length(vel);
    if (length > 0) {
        vel.x /= length;
        vel.y /= length;
    }

    float mult = (IsKeyDown(KEY_LEFT_SHIFT)) ? 0.5 : 1;

    x += vel.x * mult * PLAYER_MOVESPEED * deltaTime;
    y += vel.y * mult * PLAYER_MOVESPEED * deltaTime;
}

void Player::Draw() {
    DrawCircle(x, y, size, color);
}

Player::Player(std::vector<Entity*> *entityList) {
    x = 0;
    y = 0;
    size = 2;
    health = 100;
    type = ENTITY_PLAYER;
    color = GREEN;
    entityList->push_back(this);
}