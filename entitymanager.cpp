#include "entitymanager.h"

std::vector<Entity*> EntityManager::entitylist;

void EntityManager::DrawAll() {
    for (int i = 0; i < entitylist.size(); i++) {
        Entity *entity = entitylist.at(i);
        if (!entity)
            continue;
        entity->Draw();
    }
}

void EntityManager::UpdateAll(float dt) {
    for (int i = 0; i < entitylist.size(); i++) {
        Entity *entity = entitylist.at(i);
        if (!entity)
            continue;
        entity->Update(dt);
    }
}