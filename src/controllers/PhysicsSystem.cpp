#include "controllers/PhysicsController.h"
#include "controllers/EntityController.h"
#include "core/Constants.h"

PhysicsController::PhysicsController() : m_gravity_factor(Constants::GRAVITY) {} // pixels/sec^2 (tune to taste)

void PhysicsController::update(EntityController* manager, Player &player)
{
    applyGravity(player);
    for (auto &ePtr : manager->getEntities())
    {
        if (ePtr)
            applyGravity(*ePtr);
    }
}

// TODO: Right now gravity is constant 
void PhysicsController::applyGravity(Entity &entity)
{
    entity.m_pos.y += m_gravity_factor * GetFrameTime();
}

void PhysicsController::draw()
{
}