#include "core/Game.h"

Game::Game()
{
    Entity *player = new Player();
    Entity *enemy = new Enemy();


    // PhysicsSystem physics;
    // LevelManager level_manager;
}


void Game::update()
{
    // this->m_player.

}

void Game::draw()
{
}


void Game::setPlayer(Player _player)
{
    m_player = _player;
}

Player Game::getPlayer()
{
    return m_player;
}
