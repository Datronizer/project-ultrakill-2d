#include <raylib.h>

class GameObject
{
    public:
        GameObject();
        void update();
        void draw();

    private:
        Vector2 m_pos;
};