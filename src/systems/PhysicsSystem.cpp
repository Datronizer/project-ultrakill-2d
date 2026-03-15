#include "systems/PhysicsSystem.h"
#include "core/EntityManager.h"
#include "core/Constants.h"

PhysicsSystem::PhysicsSystem() : m_gravity_factor(Constants::GRAVITY) {} // pixels/sec^2 (tune to taste)

void PhysicsSystem::update(EntityManager &manager, Player &player)
{
    applyGravity(player);
    for (auto &ePtr : manager.getEntities())
    {
        if (ePtr)
            applyGravity(*ePtr);
    }
}

void PhysicsSystem::applyGravity(Entity &entity)
{
    entity.m_pos.y += m_gravity_factor * GetFrameTime();
}

void PhysicsSystem::draw()
{
}