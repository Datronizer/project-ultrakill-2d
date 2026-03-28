#include "controllers/EntityController.h"

ObjectPool<Entity>* EntityController::m_entities = new ObjectPool<Entity>();

EntityController::EntityController()
{
    id_counter = 0;
    m_entities->Prewarm(32);
}

void EntityController::addEntity(std::unique_ptr<Entity> entity)
{
    if (!entity) return;
    Entity *e = m_entities->GetResource();
    e->setID(id_counter++);
}

void EntityController::removeEntity()
{
    // TODO: ObjectPool has no empty() — needs active-entity tracking to release last entity
    DrawText("No entities to remove", 10, 10, 20, RED);
    // m_entities->ReleaseResource(lastEntity);
}

void EntityController::removeEntity(Entity &entity)
{
    // TODO
    // m_entities->ReleaseResource(&entity);
}

void EntityController::removeAllEntities()
{
    // TODO: ObjectPool has no bulk-release — needs active-entity tracking
}

void EntityController::update()
{
    // TODO: ObjectPool does not support iteration over active entities
}

void EntityController::draw()
{
    // TODO: ObjectPool does not support iteration over active entities
}

std::vector<std::unique_ptr<Entity>>& EntityController::getEntities()
{
    // TODO: return type is incompatible with ObjectPool<Entity>* — needs redesign
}
