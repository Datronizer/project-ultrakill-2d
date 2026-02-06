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
    
};


#endif // ENEMY_H