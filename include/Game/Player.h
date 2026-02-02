#include <raylib.h>
#include "Entity.h"

class Player : Entity
{
    public:
        Player();
        Player(Vector2 pos);
        
        // void update();
        // void draw();

        void move() {
            m_pos.x += m_speed;
            m_pos.y += m_speed;
        }
        void move(float x, float y) {
            m_pos.x += x;
            m_pos.y += y;
        }

        Vector2 getPos() { return m_pos; }
        
        void setPos(Vector2 _pos) { m_pos = _pos; }
        void setPos(float x, float y) { m_pos.x = x; m_pos.y = y; }

        float x = 0;
        float y = 0;

    private:
        Vector2 m_pos;
        float m_speed = 5;
        
        float m_health = 100;  // TODO: for now let's say it starts at 100
        int m_damage = 10;     
};