#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H


#include <raylib.h>
#include "entities/Entity.h"

class PhysicsSystem
{
    public:
        PhysicsSystem();

        void update();
        void draw();

    private:
        float m_gravity_factor;

        void applyGravity(Entity _entity);
};

#endif // PHYSICSSYSTEM_H