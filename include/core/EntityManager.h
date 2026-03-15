#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <memory>
#include "entities/Entity.h"

class EntityManager
{
    public:
        EntityManager();

        void addEntity(std::unique_ptr<Entity> entity);
        void removeEntity();
        void removeEntity(Entity &entity);
        void removeAllEntities();

        void update();
        void draw();

        std::vector<std::unique_ptr<Entity>>& getEntities();

    private:
        int id_counter = 0;

        std::vector<std::unique_ptr<Entity>> m_entities;
};


#endif // ENTITYMANAGER_H