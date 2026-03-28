#ifndef COLLIDERSYSTEM_H
#define COLLIDERSYSTEM_H

#include <vector>
#include "./EntityController.h"
#include "entities/Player.h"
#include "components/Collider.h"
#include "core/Singleton.h"

class ColliderController : public Singleton<ColliderController>
{
public:
    ColliderController();

    void attachCollider(Collider &collider, GameObject &owner);
    void update(EntityController &manager, Player &player);

private:
    std::vector<Collider *> m_colliders;
};

#endif // COLLIDERSYSTEM_H
