#include "components/Collider.h"
#include "objects/GameObject.h"

Collider::Collider() {}

Collider::Collider(GameObject *owner, Rectangle bounds)
    : m_owner(owner), m_bounds(bounds) {}

Collider::~Collider() {}

Rectangle Collider::getBounds() const
{
    if (!m_owner) return m_bounds;
    return {
        m_owner->m_pos.x + m_bounds.x,
        m_owner->m_pos.y + m_bounds.y,
        m_bounds.width,
        m_bounds.height
    };
}
