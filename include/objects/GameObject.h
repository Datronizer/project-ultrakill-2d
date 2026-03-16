#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Libraries
#include <raylib.h>
#include <vector>

// Project headers
#include "components/Component.h"


using namespace std;

class GameObject
{
    public:
        GameObject();

        virtual void draw() = 0;
        virtual void update() = 0;

        Vector2 m_pos;
        float m_rotation;

        Texture2D m_texture;
        vector<Component> m_components; 

        void attachComponent(Component &component);
        void detachComponent(Component &component);
        void getComponent(Component &component);

        ~GameObject();

    private:
        
};


#endif // GAMEOBJECT_H