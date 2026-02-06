#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <raylib.h>

class GameObject
{
    public:
        GameObject();

        virtual void draw() = 0;
        virtual void update() = 0;

        Vector2 m_pos;

        ~GameObject();

    private:
};


#endif // GAMEOBJECT_H