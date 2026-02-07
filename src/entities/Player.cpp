#include <raylib.h>
#include <raymath.h>
#include <string>
#include "core/Constants.h"
#include "entities/Player.h"

Player::Player()
{
    m_health = 25;

    m_pos.x = 200;
    m_pos.y = 200;

    m_texture = LoadTexture("assets/entities/penguin_idle.png");
}

Player::Player(Vector2 pos)
{
}

Player::~Player()
{
    UnloadTexture(m_texture);
}

void Player::update()
{
}

void Player::draw()
{
    DrawRectangle(m_pos.x, m_pos.y, 32, 32, GREEN);
    // DrawTexturePro(
    //     m_texture, 
    //     Rectangle{ 0, 0, (float)m_texture.width, (float)m_texture.height },
    //     Rectangle{ m_pos.x, m_pos.y, (float)m_texture.width * 2.0f, (float)m_texture.height * 2.0f },
    //     Vector2{ (float)m_texture.width, (float)m_texture.height }, 
    //     m_rotation, 
        // WHITE);

    // Debug
    DrawText(
        ("HP: " + std::to_string(m_health)).c_str(),
        m_pos.x,
        m_pos.y - Constants::DEBUG_TEXT_SIZE,  // Moves the text up above the player
        Constants::DEBUG_TEXT_SIZE,
        BLACK);
}
