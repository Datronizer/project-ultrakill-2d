#include <raylib.h>

class GameObject
{
    public:
        GameObject();

        Vector2 getPos();
        void setPos(Vector2);

    private:
        Vector2 m_pos;
};