#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <memory>
#include "entities/Entity.h"
#include "entities/Player.h"

class EntityManager
{
    public:
        EntityManager();

        void addEntity(std::unique_ptr<Entity> entity);
        void removeEntity();
        void removeEntity(Entity &entity);
        void removeAllEntities();

        void addPlayer(const Player &player);
        void removePlayer();  // I don't know when we would ever need this but whatevs

        void update();
        void draw();

        std::vector<std::unique_ptr<Entity>>& getEntities();
        const Player& getPlayer() const;

    private:
        int id_counter = 0;

        Player m_player;  // Let's treat player as a special case
        std::vector<std::unique_ptr<Entity>> m_entities;
};


#endif // ENTITYMANAGER_H