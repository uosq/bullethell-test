#ifndef ENTITYMANAGER_INCLUDE
#define ENTITYMANAGER_INCLUDE

#include "entity.h"

class EntityManager {
public:
    static std::vector<Entity*> entitylist;

    static void Add(Entity *e) {entitylist.push_back(e);}
    static void UpdateAll(float dt);
    static void DrawAll();
};

#endif