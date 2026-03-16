#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <memory>
#include "entities/Entity.h"

using namespace std;

class EntityManager
{
    public:
        EntityManager();

        void addEntity(unique_ptr<Entity> entity);
        void removeEntity();
        void removeEntity(Entity &entity);
        void removeAllEntities();

        void update();
        void draw();

        vector<unique_ptr<Entity>>& getEntities();

    private:
        int id_counter = 0;

        vector<unique_ptr<Entity>> m_entities;
};


#endif // ENTITYMANAGER_H