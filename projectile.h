#ifndef PROJECTILE_INCLUDE
#define PROJECTILE_INCLUDE

#include "entity.h"
#include "raylib.h"
#include <raymath.h>
#include <stdlib.h>
#include <vector>

class Projectile : public Entity {
public:
    /* fields */
    Vector2 speed;

    /* methods */
    void Update(float dt) override;
    void Draw() override;

    Projectile();
};

#endif