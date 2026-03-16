#ifndef COLLIDER_H
#define COLLIDER_H

#include <raylib.h>
#include "components/Component.h"

class GameObject;

/**
 * A collider is a component that makes an entity collide with other entities.
 * bounds.x/y are offsets from the owner's position; width/height are the collider size.
 */
class Collider : public Component
{
public:
    Collider();
    Collider(GameObject *owner, Rectangle bounds);
    ~Collider();

    Rectangle getBounds() const;  // returns world-space bounds

    GameObject *m_owner = nullptr;
    Rectangle m_bounds = {0, 0, 0, 0};
    bool m_static = false;  // static colliders are immovable (e.g. floor, walls)
};

#endif // COLLIDER_H
