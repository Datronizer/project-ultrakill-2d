#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <memory>

#include "entities/Entity.h"
#include "core/Singleton.h"
#include "core/ObjectPool.h"

using namespace std;

class EntityController : public Singleton<EntityController>
{
    public:
        EntityController();

        void addEntity(unique_ptr<Entity> entity);
        void removeEntity();
        void removeEntity(Entity &entity);
        void removeAllEntities();

        void update();
        void draw();

        vector<unique_ptr<Entity>>& getEntities();

        static ObjectPool<Entity> *m_entities;

    private:
        int id_counter = 0;
};


#endif // ENTITYMANAGER_H