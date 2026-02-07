#include "systems/PhysicsSystem.h"
#include "core/EntityManager.h"
#include "core/Constants.h"

PhysicsSystem::PhysicsSystem() : m_gravity_factor(Constants::GRAVITY) {} // pixels/sec^2 (tune to taste)

void PhysicsSystem::update(EntityManager &manager)
{
    const float dt = 1.0f / Constants::TARGET_FPS;
    for (auto &ePtr : manager.getEntities())
    {
        if (ePtr)
            applyGravity(*ePtr);
    }
}

void PhysicsSystem::applyGravity(Entity &entity)
{
    // entity.m_pos.y += m_gravity_factor * (1.0f / Constants::TARGET_FPS);
}

void PhysicsSystem::draw()
{
}