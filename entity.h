#ifndef ENTITY_INCLUDE
#define ENTITY_INCLUDE

#include "raylib.h"
#include <vector>

typedef enum {
    ENTITY_PLAYER = 0,
    ENTITY_PROJECTILE
} EntityType;

class Entity {
protected:
    float x, y;
    Color color;
    int type;
    int size;
    bool colliding;

public:
    void SetPosition(int x, int y);
    void SetColor(Color color);
    void SetType(EntityType type);
    void SetSize(int size);
    void SetColliding(int collision);

    Vector2 GetPosition();
    int GetSize();
    int GetType();
    Color GetColor();
    bool IsColliding();

    virtual void Draw();
    virtual void Update(float dt) = 0;

    Entity();

    virtual ~Entity() {};
};

#endif