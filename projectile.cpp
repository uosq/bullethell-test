#include "projectile.h"
#include "entity.h"
#include <vector>

void Projectile::Draw() {
    if (x > 800 || x < 0 || y < 0 || y > 800)
        return; // out of bounds

    DrawCircle(x, y, size, color);
}

void Projectile::Update(float deltaTime) {
    x += speed.x * deltaTime;
    y += speed.y * deltaTime;
}

Projectile::Projectile(std::vector<Entity*> *entitylist) {
    entitylist->push_back(this);
    this->type = ENTITY_PROJECTILE;
}