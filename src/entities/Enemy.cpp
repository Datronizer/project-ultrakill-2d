#include "entities/Enemy.h"
#include <cmath>


Enemy::Enemy()
{
    int randDist = GetRandomValue(-150, 150);

    m_pos.x = 500 + randDist;
    m_pos.y = GetRandomValue(0, 200);
}

void Enemy::update()
{
    
}

void Enemy::draw()
{
    DrawRectangle(m_pos.x, m_pos.y, 25, 25, RED);
}

void Enemy::lookAtPlayer(const Vector2 &player_pos)
{
    Vector2 thisPos = this->getPosition();
    float dx = player_pos.x - thisPos.x;
    float dy = player_pos.y - thisPos.y;

    float angleDeg = atan2f(dy, dx) * (180.0f / PI);
    this->setRotation(angleDeg);
}