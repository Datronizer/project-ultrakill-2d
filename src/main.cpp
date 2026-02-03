#include <iostream>
#include <raylib.h>
#include "../include/Game.h"

using namespace std;

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    Game game;
    InitWindow(screenWidth, screenHeight, "Project 2D Ultrakill");

    // Init player
    // Player player;
    // player.setPos(Vector2{ (float)screenWidth / 2, (float)screenHeight / 2 });

    SetTargetFPS(60);


    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        game.update();

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