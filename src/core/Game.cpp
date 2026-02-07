#include "core/Game.h"

Game::Game()
{
    // Systems

    // Managers
    this->m_entity_manager = EntityManager();

    // Initialize entities
    this->m_player = Player();

    // TODO: temp
    m_entity_manager.addEntity(std::make_unique<Enemy>());

    // PhysicsSystem physics;
    // LevelManager level_manager;
}


void Game::update()
{
    // Controls
    if (IsKeyDown(KEY_RIGHT)) this->m_player.m_pos.x += 5;
    if (IsKeyDown(KEY_LEFT)) this->m_player.m_pos.x -= 5;
    if (IsKeyDown(KEY_UP)) this->m_player.m_pos.y -= 5;
    if (IsKeyDown(KEY_DOWN)) this->m_player.m_pos.y += 5;

    if (IsKeyPressed(KEY_SPACE)) m_entity_manager.addEntity(std::make_unique<Enemy>());

    // Physics
    // m_physics.update();
}

void Game::draw()
{
    this->m_player.draw();

    m_entity_manager.draw();
}


void Game::setPlayer(Player _player)
{
    m_player = _player;
}

Player Game::getPlayer()
{
    return m_player;
}
