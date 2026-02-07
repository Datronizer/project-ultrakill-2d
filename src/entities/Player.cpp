#include <raylib.h>
#include <raymath.h>
#include <string>
#include "core/Constants.h"
#include "entities/Player.h"

Player::Player()
{
    m_health = 25;

    m_pos.x = 0;
    m_pos.y = 0;
}

Player::Player(Vector2 pos)
{
}

void Player::update()
{
}

void Player::draw()
{
    DrawRectangle(m_pos.x, m_pos.y, 50, 50, GREEN);

    // Debug
    DrawText(
        ("HP: " + std::to_string(m_health)).c_str(),
        m_pos.x,
        m_pos.y - Constants::DEBUG_TEXT_SIZE,  // Moves the text up above the player
        Constants::DEBUG_TEXT_SIZE,
        BLACK);
}
