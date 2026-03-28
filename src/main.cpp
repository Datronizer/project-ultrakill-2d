#include <iostream>
#include <raylib.h>
#include "../include/core/Game.h"
#include "../include/core/Constants.h"

using namespace std;
using namespace Constants;

int main()
{
    // Initialization
    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;

    InitWindow(screenWidth, screenHeight, "Project 2D Ultrakill");
    Game game;


    SetTargetFPS(TARGET_FPS);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        game.update(); // TODO: this might do weird things with physics since its not fixed timestep

        // --- Update goes here
        // ---

        // player.update();

        // --- Movement

        // ---

        // --- Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        game.draw();

        DrawText("Hello World!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        // ---
    }

    CloseWindow();

    return 0;
}