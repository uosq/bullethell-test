#include "entitymanager.h"
#include "projectile.h"
#include "enemy.h"

void Enemy::Update(float dt) {
    double time = GetTime();

    if (time >= nextSpawnTime) {
        nextSpawnTime = time + spawn_interval;
        SpawnProjectile();
    }
}

void Enemy::SpawnProjectile() {
    float rotationSpeed = 1.5f; // radians/sec
    float baseAngle = rotationSpeed * GetTime();

    for (int i = 0; i < numBullets; i++) {
        float randomOffset = GetRandomValue(0, 314) / 100.0f; // 0 to ~3.14 radians
        float angle = baseAngle + i * 2 * PI / numBullets + randomOffset;

        Projectile *bullet = new Projectile();
        Vector2 pos = GetPosition();
        bullet->SetPosition(pos.x, pos.y);
        bullet->SetSize(GetRandomValue(4, 15));
        bullet->SetColor(ColorFromHSV(GetRandomValue(0, 360), 0.5f, 1.f));

        float speedMagnitude = GetRandomValue(80, 120);
        bullet->speed = { cos(angle) * speedMagnitude, sin(angle) * speedMagnitude };
        entityManager->Add(bullet);
    }
}

Enemy::Enemy(EntityManager *manager) {
    entityManager = manager;
}