#include "entity.h"
#include <raylib.h>

Entity::Entity() {
    x = 0;
    y = 0;
    color = WHITE;
    type = ENTITY_PLAYER;
    size = 10;
}

void Entity::SetColor(Color newcolor) {
    color = newcolor;
}

void Entity::SetPosition(int newx, int newy) {
    x = newx;
    y = newy;
}

void Entity::SetSize(int newsize) {
    size = newsize;
}

Vector2 Entity::GetPosition() {
    return (Vector2){x, y};
}

Color Entity::GetColor() {
    return color;
}

int Entity::GetSize() {
    return size;
}

int Entity::GetType() {
    return type;
}

void Entity::SetColliding(int collision) {
    colliding = collision;
}

void Entity::Draw() {
    DrawCircle(x, y, size, color);
}