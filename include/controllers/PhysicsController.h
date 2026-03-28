#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <raylib.h>
#include "entities/Entity.h"
#include "entities/Player.h"
#include "controllers/EntityController.h"
#include "core/Singleton.h"

class PhysicsController : public Singleton<PhysicsController>
{
public:
    PhysicsController();

    void update(EntityController *manager, Player &player);
    void draw();

private:
    float m_gravity_factor;

    void applyGravity(Entity &entity);
};

#endif // PHYSICSSYSTEM_H