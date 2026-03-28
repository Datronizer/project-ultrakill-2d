#include "controllers/EntityController.h"


EntityController::EntityController()
{
    id_counter = 0;
    m_entities.reserve(32);
}

void EntityController::addEntity(std::unique_ptr<Entity> entity)
{
    if (!entity) return;
    entity->setID(id_counter++);

    m_entities.push_back(std::move(entity));
}
void EntityController::removeEntity()
{
    if (m_entities.empty()) {
        DrawText("No entities to remove", 10, 10, 20, RED);
        return;
    };
    // TODO
    m_entities.pop_back();
}
void EntityController::removeEntity(Entity &entity)
{
    if (m_entities.empty()) {
        DrawText("No entities to remove", 10, 10, 20, RED);
        return;
    };

    // TODO
    // m_entities.erase()
}

void EntityController::removeAllEntities()
{
    m_entities.clear();
}

void EntityController::update()
{
    for (auto &entity : m_entities)
    {
        if (entity) entity->update();
    }
}
void EntityController::draw()
{
    for (auto &entity : m_entities)
    {
        if (entity) entity->draw(); 
    }
}

std::vector<std::unique_ptr<Entity>> &EntityController::getEntities()
{
    // TODO: insert return statement here
    return m_entities;
}
