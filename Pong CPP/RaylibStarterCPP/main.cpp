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
    float deltatime = 0.005f;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    bool isDebug = false;

    //Player1 variable declarations
    float p1x = 100;
    float p1y = 150;
    //Collision Stuff
    float p1yLowerLimit = p1y - 10;
    float p1yUpperLimit = p1y + 120;

    float p1Width = 20;
    float p1Height = 125;

    float p1Speed = 1000;
    float p1Score = 0;

    //Player2 Variable declarations
    float p2x = 700;
    float p2y = 150;
    //Collision Stuff
    float p2yLowerLimit = p2y - 10;
    float p2yUpperLimit = p2y + 150;
    //I know there is no reason to keep this in memory because we already have the value from p1 but it's less confusing to read this way for a larger project
    // I'd care but for something small like this it doesn't change much
    float p2Width = 20;
    float p2Height = 125;

    float p2Speed = 1000;
    float p2Score = 0;

    //Ball Variables
    float ballx = 400;
    float bally = 200;

    float ballWidth = 20;
    float ballHeight = 20;

    float ballSpeed = 600;
    int ballxDirection = 1;
    int ballyDirection = 0;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        /*player 1 movement : if player is holding W then decrease Y coordinate to make the player 1 paddle go up (this is because the window is essentially in
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
        //Player 2 controls
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

        if (IsKeyReleased(KEY_E))
        {
            if (isDebug == false)
            {
                isDebug == true;
            }
            else
            {
                isDebug == false;
            }
        }

        // update htibox boundary player 1
        p1yLowerLimit = p1y - 10;
        p1yUpperLimit = p1y + 120;
        // update htibox boundary player 2
        p2yLowerLimit = p2y - 10;
        p2yUpperLimit = p2y + 120;

        //ball movement
        ballx = ballx + ballxDirection * ballSpeed * deltatime;
        //check ball collision with player 1 paddle
        if (ballx == p1x && bally >= p1yLowerLimit && bally <= p1yUpperLimit)
        {
            ballxDirection = 1;
        }

        //check ball collision with player 2 paddle
        if (ballx == p2x && bally >= p2yLowerLimit && bally < p2yUpperLimit)
        {
            ballxDirection = -1;
        }
        


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        // DEBUG SHOW HITBOUNDARY
        if (isDebug == true)
        {
            //draws player 1 Hitbox upper
            DrawRectangle(p1x, p1yUpperLimit, 20, 20, RED);
            //draws player 1 Hitbox bottom
            DrawRectangle(p1x, p1yLowerLimit, 20, 20, RED);
            //draws player 2 Hitbox upper
            DrawRectangle(p2x, p2yUpperLimit, 20, 20, RED);
            //draws player 2 Hitbox bottom
            DrawRectangle(p2x, p2yLowerLimit, 20, 20, RED);
        }

        //draws player 1 paddle
        DrawRectangle(p1x, p1y, p1Width, p1Height, BLACK);
        //draws player 2 paddle
        DrawRectangle(p2x, p2y, p1Width, p1Height, BLACK);
        //draws Ball
        DrawRectangle(ballx, bally, ballWidth, ballHeight, BLACK);

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