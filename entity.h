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

    Vector2 GetPosition();
    int GetSize();
    int GetType();
    Color GetColor();
    bool IsColliding(std::vector<Entity*> *entitylist);

    virtual void Draw() = 0;
    virtual void Update(float dt) = 0;

    Entity(std::vector<Entity*> *entitylist);
    Entity();

    virtual ~Entity() {};
};

#endif