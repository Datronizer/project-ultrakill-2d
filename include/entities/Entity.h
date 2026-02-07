#ifndef ENTITY_H
#define ENTITY_H


#include <raylib.h>
#include "objects/GameObject.h"


class Entity : public GameObject
{
    public:
        Entity();

        int m_health = 100;

        int getID();
        void setID(const int &id);
        
        Vector2 getPosition();
        void setPosition(const Vector2 &pos);

        float getRotation();
        void setRotation(const float &angle);

    private:
        unsigned int m_id;
};


#endif // ENTITY_H