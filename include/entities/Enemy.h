#include <raylib.h>
#include "Entity.h"

class Enemy : public Entity
{
    public:
        Enemy();

        void update();
        void draw();
    
};