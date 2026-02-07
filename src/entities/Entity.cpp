#include "entities/Entity.h"


Entity::Entity()
{
    m_pos.x = 0;
    m_pos.y = 0;
    m_rotation = 0;
}

int Entity::getID()
{
    return m_id;
}
void Entity::setID(const int &id)
{
    m_id = id;
}

Vector2 Entity::getPosition() 
{
    return m_pos;
}
void Entity::setPosition(const Vector2 &pos)
{
    m_pos = pos;
}

float Entity::getRotation()
{
    return m_rotation;
}
void Entity::setRotation(const float &angle)
{
    m_rotation = angle;
}