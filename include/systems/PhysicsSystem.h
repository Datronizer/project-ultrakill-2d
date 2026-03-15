#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H


#include <raylib.h>
#include "entities/Entity.h"
#include "entities/Player.h"

class PhysicsSystem
{
    public:
        PhysicsSystem();

        void update(class EntityManager &manager, Player &player);
        void draw();

    private:
        float m_gravity_factor;

        void applyGravity(Entity &entity);
};

#endif // PHYSICSSYSTEM_H