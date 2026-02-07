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
void EntityManager::removeEntity()
{
    if (m_entities.empty()) {
        DrawText("No entities to remove", 10, 10, 20, RED);
        return;
    };
    // TODO
    m_entities.pop_back();
}
void EntityManager::removeEntity(Entity &entity)
{
    if (m_entities.empty()) {
        DrawText("No entities to remove", 10, 10, 20, RED);
        return;
    };

    // TODO
    // m_entities.erase()
}

void EntityManager::removeAllEntities()
{
    m_entities.clear();
}

void EntityManager::addPlayer(const Player &player)
{
    m_player = player;
}
void EntityManager::removePlayer()
{
    // TODO
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

std::vector<std::unique_ptr<Entity>> &EntityManager::getEntities()
{
    // TODO: insert return statement here
    return m_entities;
}
const Player &EntityManager::getPlayer() const
{
    return m_player;
}