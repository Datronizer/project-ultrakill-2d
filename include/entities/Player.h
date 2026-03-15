#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>
#include "entities/Entity.h"

class Player : public Entity
{
    public:
        Player();
        Player(Vector2 pos);
        ~Player();

        void update();
        void draw();

    private:
        
};


#endif // PLAYER_H