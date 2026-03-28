#ifndef GAME_H
#define GAME_H

#include <raylib.h>

#include "entities/Player.h"
#include "entities/Enemy.h"
#include "controllers/PhysicsController.h"
#include "controllers/ColliderController.h"
#include "controllers/LevelController.h"
#include "controllers/EntityController.h"
#include "objects/Floor.h"
#include "components/Collider.h"


/**
 * The game class is the main class for the game.
 */
class Game
{
    public:
        Game();
        void update();
        void draw();

        void setPlayer(Player _player);
        Player getPlayer();  // For now, this game will only have 1 player, so getPlayer just... gets player

    private:
        // Systems
        PhysicsController* m_physics;
        ColliderController* m_collider_system;

        // Managers
        EntityController* m_entity_manager;

        // Entities
        Player m_player;

        // Objects
        Floor m_floor;

        // Colliders
        Collider m_player_collider;
        Collider m_floor_collider;

        // float m_gravity_factor;      
};

#endif // GAME_H