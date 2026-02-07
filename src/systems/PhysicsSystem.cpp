#include "systems/PhysicsSystem.h"
#include "core/EntityManager.h"

PhysicsSystem::PhysicsSystem() : m_gravity_factor(200.0f) {} // pixels/sec^2 (tune to taste)

void PhysicsSystem::update(EntityManager &manager)
{
    // simple fixed-timestep application (assuming 60 FPS)
    const float dt = 1.0f/60.0f;
    for (auto &ePtr : manager.getEntities())
    {
        if (ePtr) applyGravity(*ePtr);
    }
}

void PhysicsSystem::applyGravity(Entity &entity)
{
    entity.m_pos.y += m_gravity_factor * (1.0f/60.0f);
}

void PhysicsSystem::draw()
{
    
}