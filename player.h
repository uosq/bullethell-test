#ifndef PLAYER_INCLUDE
#define PLAYER_INCLUDE

#include "entity.h"
#include "raylib.h"
#include <raymath.h>
#include <stdlib.h>

#define PLAYER_MOVESPEED 100

class Player : public Entity {
public:
    /* fields */
    int health;

    /* methods */
    void Draw() override;
    void Update(float dt) override;

    Player(std::vector<Entity*> *entityList);
};

#endif