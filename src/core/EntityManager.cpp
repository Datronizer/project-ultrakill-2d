#include "core/EntityManager.h"

EntityManager::EntityManager()
{
    id_counter = 0;
    m_entities.reserve(32);
}

void EntityManager::addEntity(std::unique_ptr<Entity> entity)
{
    if (!entity) return;
    entity->setID(id_counter++);

    m_entities.push_back(std::move(entity));
}
void EntityManager::removeEntity(Entity &entity)
{
    // TODO
    // m_entities.erase()
}

void EntityManager::update()
{
    for (auto &entity : m_entities)
    {
        if (entity) entity->update();
    }
}
void EntityManager::draw()
{
    for (auto &entity : m_entities)
    {
        if (entity) entity->draw(); 
    }
}