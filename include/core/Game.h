#ifndef GAME_H
#define GAME_H

#include <raylib.h>

#include "entities/Player.h"
#include "entities/Enemy.h"
#include "systems/PhysicsSystem.h"
#include "core/LevelManager.h"
#include "core/EntityManager.h"


class Game
{
    public:
        Game();
        void update();
        void draw();

        void setPlayer(Player _player);
        Player getPlayer();  // For now, this game will only have 1 player, so getPlayer just... gets player

    private:
        // // Systems
        PhysicsSystem m_physics;
        
        // // Managers
        // LevelManager m_level_manager;
        EntityManager m_entity_manager;

        // Entities
        Player m_player;


        // float m_gravity_factor;      
};

#endif // GAME_H