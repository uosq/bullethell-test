#ifndef ENEMY_INCLUDE
#define ENEMY_INCLUDE

#include "entity.h"
#include "entitymanager.h"

class Enemy: public Entity {
private:
    std::vector<Entity*> *entitylist;
    double nextSpawnTime = 0.0f;
    float spawn_interval = 0.5f;
    int numBullets = 3;
    EntityManager *entityManager;

public:
    void Update(float dt) override;
    void SpawnProjectile();
    void SetBulletNumber(int number) {numBullets = number;}
    Enemy(EntityManager *manager);
};

#endif