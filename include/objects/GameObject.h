#include <raylib.h>

class GameObject
{
    public:
        GameObject();

        virtual void draw() = 0;
        virtual void update() = 0;

        ~GameObject();

    private:
        // Vector2 m_pos;
};