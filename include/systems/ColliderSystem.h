#ifndef COLLIDERSYSTEM_H
#define COLLIDERSYSTEM_H

#include <vector>
#include "core/EntityManager.h"
#include "entities/Player.h"
#include "components/Collider.h"

class ColliderSystem
{
public:
    ColliderSystem();

    void attachCollider(Collider &collider, GameObject &owner);
    void update(EntityManager &manager, Player &player);

private:
    std::vector<Collider *> m_colliders;
};

#endif // COLLIDERSYSTEM_H
