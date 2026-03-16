#ifndef FLOOR_H
#define FLOOR_H

#include "objects/GameObject.h"

class Floor : public GameObject
{
public:
    Floor();
    ~Floor();

    void update();
    void draw();
};

#endif // FLOOR_H