#ifndef ENEMY_H
#define ENEMY_H

#include <raylib.h>
#include "Entity.h"

class Enemy : public Entity
{
    public:
        Enemy();

        void update();
        void draw();

        void lookAtPlayer(const Vector2 &player_pos);
    
    private:
        
};


#endif // ENEMY_H