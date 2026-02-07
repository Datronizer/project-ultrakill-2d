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
        void removeEntity(Entity &entity);

        void update();
        void draw();
    
    private:
        int id_counter = 0;
        std::vector<std::unique_ptr<Entity>> m_entities;
};


#endif // ENTITYMANAGER_H