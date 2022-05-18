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

    //Player2 Variable
    float p2x = 700;
    float p2y = 150;
    //I know there is no reason to keep this in memory because we already have the value from p1 but it's less confusing to read this way for a larger project
    // I'd care but for something small like this it doesn't change much
    float p2Width = 20;
    float p2Height = 125;

    float p2Speed = 1000;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        /*player one movement : if player is holding W then decrease Y coordinate to make the player 1 paddle go up (this is because the window is essentially in
        the bottom right quadrant of a number plane thus in it's current position decreasing the y value makes the paddle go up)*/ 
        if (IsKeyDown(KEY_W))
        {
            p1y = p1y + -1 * p1Speed * deltatime;
            if (p1y < 0)
            {
                p1y = 0;
            }
        }
        if (IsKeyDown(KEY_S))
        {
            p1y = p1y + 1 * p1Speed * deltatime;
            if (p1y > 325)
            {
                p1y = 325;
            }
        }
        
        if (IsKeyDown(KEY_UP))
        {
            p2y = p2y + -1 * p2Speed * deltatime;
            if (p2y < 0)
            {
                p2y = 0;
            }
        }
        if (IsKeyDown(KEY_DOWN))
        {
            p2y = p2y + 1 * p1Speed * deltatime;
            if (p2y > 325)
            {
                p2y = 325;
            }
        }

        // Draw
        //----------------------------------------------------------------------------------
        counter++;
        BeginDrawing();

        ClearBackground(RAYWHITE);
        //draws player 1 paddle
        DrawRectangle(p1x, p1y, p1Width, p1Height, BLACK);
        //draws player 2 paddle
        DrawRectangle(p2x, p2y, p1Width, p1Height, BLACK);
        //draws score text
        DrawText("0", 350, 20, 80, LIGHTGRAY);
        DrawText("|", 410, 20, 80, LIGHTGRAY);
        DrawText("0", 440, 20, 80, LIGHTGRAY);
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}