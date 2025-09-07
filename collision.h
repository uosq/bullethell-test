#include "entity.h"
#include <raylib.h>

class Collision {
public:
    static bool IsColliding(Entity* a, Entity* b) {
        Vector2 aPos, bPos;
        aPos = a->GetPosition();
        bPos = b->GetPosition();

        bool collision = CheckCollisionCircles({aPos.x, aPos.y}, a->GetSize(), {bPos.x, bPos.y}, b->GetSize());

        // both are colliding with eachother sooo
        a->SetColliding(collision);
        b->SetColliding(collision);
        return collision;
    }

    static bool IsCollidingWithAny(Entity* e, const std::vector<Entity*>& entities) {
        for (int i = 0; i < entities.size(); i++) {
            Entity *entity = entities.at(i);
            if (!entity || entity == e)
                continue;
            if (IsColliding(e, entity))
                return true;
        }

        return false;
    }
};