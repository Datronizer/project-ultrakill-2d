#ifndef COMPONENT_H
#define COMPONENT_H

/**
 * Base class for all components
 * 
 * A component is a piece of data that can be attached to an entity to add functionality (e.g. a collider).
 * 
 * @example Colliders are components that make things collide with each other
 * @example Physics are components that allow entities to be affected by gravity and other forces
 */
class Component
{
public:
    Component();
    ~Component();
};

#endif // COMPONENT_H