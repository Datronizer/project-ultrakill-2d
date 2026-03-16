#include "objects/GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{
}

void GameObject::attachComponent(Component &component)
{
    m_components.push_back(component);
}

void GameObject::detachComponent(Component &component)
{
    // TODO
}

void GameObject::getComponent(Component &component)
{
    // TODO
}