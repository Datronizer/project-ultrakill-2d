#include <raylib.h>
#include "Player.h"

class Game
{
    public:
        Game();
        void update();
        void draw();

    private:
        Player m_player;
};