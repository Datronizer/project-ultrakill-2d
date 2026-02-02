#include <raylib.h>
#include "GameObject.h"

class Entity : GameObject
{
    public:
        Entity();
        void update();
        void draw();

    private:
        Vector2 m_pos;
        float m_speed = 5;
        float m_health = 100;
        int m_damage = 10;
};