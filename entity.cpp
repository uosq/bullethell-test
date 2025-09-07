#include "entity.h"
#include <raylib.h>
#include <vector>

Entity::Entity(std::vector<Entity*> *entitylist) {
    x = 0;
    y = 0;
    color = WHITE;
    type = ENTITY_PLAYER;
    size = 10;
    entitylist->push_back(this);
}

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

bool Entity::IsColliding(std::vector<Entity*> *entitylist) {
    for (int i = 0; i < entitylist->size(); i++) {
        Entity *entity = entitylist->at(i);
        if (!entity || entity == this)
            continue;

        if (CheckCollisionCircles((Vector2){x, y}, size, (Vector2){entity->x, entity->y}, entity->size))
            return true;
    }

    return false;
}