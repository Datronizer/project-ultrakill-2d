#include <iostream>
#include <raylib.h>
#include "../include/core/Game.h"
#include "../include/core/Constants.h"

using namespace std;

int main()
{
    // Initialization
    const int screenWidth = Constants::SCREEN_WIDTH;
    const int screenHeight = Constants::SCREEN_HEIGHT;

    Game game;
    InitWindow(screenWidth, screenHeight, "Project 2D Ultrakill");

    // Init player
    // Player player;
    // player.setPos(Vector2{ (float)screenWidth / 2, (float)screenHeight / 2 });

    SetTargetFPS(Constants::TARGET_FPS);


    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        game.update();  // TODO: this might do weird things with physics since its not fixed timestep
        game.draw();

        // --- Update goes here
        // if (IsKeyDown(KEY_RIGHT)) player.setPos(Vector2{ player.getPos().x + 5, player.getPos().y });
        // if (IsKeyDown(KEY_LEFT)) player.setPos(Vector2{ player.getPos().x - 5, player.getPos().y });
        // if (IsKeyDown(KEY_UP)) player.setPos(Vector2{ player.getPos().x, player.getPos().y - 5 });
        // if (IsKeyDown(KEY_DOWN)) player.setPos(Vector2{ player.getPos().x, player.getPos().y + 5 });
        // ---

        // player.update();

        // --- Movement

        // ---

        // --- Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // string textPlayerPos = "Player Position: " + to_string(player.getPos().x) + ", " + to_string(player.getPos().y);

        DrawText("Hello World!", 190, 200, 20, LIGHTGRAY);
        // DrawText(textPlayerPos.c_str(), 190, 230, 20, GRAY);

        // DrawCircleV(player.getPos(), 40, RED);

        EndDrawing();
        // ---
    }

    CloseWindow();

    return 0;
}