#include "entities/Enemy.h"

Enemy::Enemy()
{
}

void Enemy::update()
{
    
}

void Enemy::draw()
{
    DrawRectangle(m_pos.x, m_pos.y, 100, 100, RED);
}