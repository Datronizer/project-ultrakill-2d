#include <raylib.h>
#include "entities/Player.h"

class Game
{
    public:
        Game();
        void update();
        void draw();

        void setPlayer(Player _player);
        Player getPlayer();  // For now, this game will only have 1 player, so getPlayer just... gets player

    private:
        Player m_player;

        float m_gravity_factor;      
};