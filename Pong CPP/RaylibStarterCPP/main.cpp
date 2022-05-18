#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    int counter = 1;
    float deltatime = 0.005f;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    //Player1 variable declarations
    float p1x = 100;
    float p1y = 150;
    float p1Width = 20;
    float p1Height = 125;

    float p1Speed = 1000;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_W))
        {
            p1y = p1y + -1 * p1Speed * deltatime;
        }

        if (IsKeyDown(KEY_S))
        {
            p1y = p1y + 1 * p1Speed * deltatime;
        }
        
        // Draw
        //----------------------------------------------------------------------------------
        counter++;
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangle(p1x, p1y, p1Width, p1Height, BLACK);
        DrawText("counterText", 190, 200, 20, LIGHTGRAY);
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}