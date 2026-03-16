#include <raylib.h>

#include "core/Constants.h"
#include "objects/GameObject.h"
#include "objects/Floor.h"

Floor::Floor()
{
    
}

Floor::~Floor()
{
}

void Floor::update()
{
    // TODO: Make sure any entity on the floor collides with the floor (can't pass through)
}
void Floor::draw()
{
    DrawRectangle(50, Constants::SCREEN_HEIGHT - 100, Constants::SCREEN_WIDTH - 100, 80, BLUE);
}