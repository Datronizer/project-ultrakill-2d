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