#include <raylib.h>
#include "entities/Player.h"

Player::Player()
{
    // m_pos.x = 0;
    // m_pos.y = 0;
}

Player::Player(Vector2 pos)
{
}

void Player::draw()
{
    DrawRectangle(m_pos.x, m_pos.y, 100, 100, GREEN);
}
 // void Player::move()
// {

// }
