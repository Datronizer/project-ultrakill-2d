#include "core/Game.h"
#include "core/Constants.h"

Game::Game()
{
    // Managers
    m_entity_manager = &EntityController::Instance();
    m_physics = &PhysicsController::Instance();
    m_collider_system = &ColliderController::Instance();

    // Entities
    this->m_player = Player();

    m_entity_manager->addEntity(std::make_unique<Enemy>());

    // Floor position must match Floor::draw()
    m_floor.m_pos = {50, Constants::SCREEN_HEIGHT - 100.0f};

    // Attach colliders
    m_player_collider = Collider(&m_player, {0, 0, 32, 32});
    m_floor_collider = Collider(&m_floor, {0, 0, Constants::SCREEN_WIDTH - 100.0f, 80});
    m_floor_collider.m_static = true;
    m_collider_system->attachCollider(m_player_collider, m_player);
    m_collider_system->attachCollider(m_floor_collider, m_floor);
}

void Game::update()
{
    // Controls
    if (IsKeyDown(KEY_RIGHT))
        this->m_player.m_pos.x += 5;
    if (IsKeyDown(KEY_LEFT))
        this->m_player.m_pos.x -= 5;
    if (IsKeyDown(KEY_UP))
        this->m_player.m_pos.y -= 5;
    if (IsKeyDown(KEY_DOWN))
        this->m_player.m_pos.y += 5;

    if (IsKeyPressed(KEY_SPACE))
        m_entity_manager->addEntity(std::make_unique<Enemy>());
    if (IsKeyPressed(KEY_BACKSPACE))
        m_entity_manager->removeEntity();

    // Physics
    m_physics->update(m_entity_manager, m_player);
    m_collider_system->update(*m_entity_manager, m_player);
}

void Game::draw()
{
    this->m_player.draw();

    m_entity_manager->draw();
    m_floor.draw();
}

void Game::setPlayer(Player _player)
{
    m_player = _player;
}

Player Game::getPlayer()
{
    return m_player;
}
