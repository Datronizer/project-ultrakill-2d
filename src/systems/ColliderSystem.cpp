#include "systems/ColliderSystem.h"
#include "systems/PhysicsSystem.h"

ColliderSystem::ColliderSystem()
{
    m_colliders.reserve(32);
}

void ColliderSystem::attachCollider(Collider &collider, GameObject &owner)
{
    collider.m_owner = &owner;
    owner.attachComponent(collider);
    m_colliders.push_back(&collider);
}

void ColliderSystem::update(EntityManager &manager, Player &player)
{
    for (size_t i = 0; i < m_colliders.size(); i++)
    {
        for (size_t j = i + 1; j < m_colliders.size(); j++)
        {
            Rectangle a = m_colliders[i]->getBounds();
            Rectangle b = m_colliders[j]->getBounds();
            if (CheckCollisionRecs(a, b))
            {
                // TODO: notify owners
                DrawText("Collision!", 10, 10, 20, RED);

                // Stop movement on the colliding objects
                
                m_colliders[i]->m_owner->m_pos.x = a.x;
                m_colliders[i]->m_owner->m_pos.y = a.y;
            }
        }
    }
}
