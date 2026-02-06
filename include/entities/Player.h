#ifndef PLAYER_H
#define PLAYER_H


#include <raylib.h>
#include "Entity.h"

class Player : public Entity
{
    public:
        Player();
        Player(Vector2 pos);

        void update();
        void draw();

    private:
        
};


#endif // PLAYER_H