#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include <string>

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------

    /* a few things to note about this code. It does not use a header file.Indead very bad no reason for doing this besides I forgot about it untl
        I wrote out everything. Another thing of note. No classes. I should of course use classes however when I started coming up with how I could do this
        I'll admit I got a little carried away and just started writing code willy nilly not really thinking about what I was doing and now if I want classes I'll
        have to refactor everything cause I was silly and didn't think it through. Other than that the code works fine it's just not following code practices
        that I should be doing */

    int screenWidth = 800;
    int screenHeight = 450;
    float deltatime = 0.005f;
    InitWindow(screenWidth, screenHeight, "Pong C++");

    bool isDebug = false;

    //Player1 variable declarations
    float p1x = 100;
    float p1y = 150;
    int p1movementDirection = 0;

    //Collision Stuff
    float p1yLowerLimit = p1y - 10;
    float p1yUpperLimit = p1y + 120;

    float p1xLowerLimit = p1x - 10;
    float p1xUpperLimit = p1x + 10;

    float p1Width = 20;
    float p1Height = 125;

    float p1Speed = 1200;
    int p1Score = 0;

    //Player2 Variable declarations
    float p2x = 700;
    float p2y = 150;
    int p2movementDirection = 0;
    //Collision Stuff
    float p2yLowerLimit = p2y - 10;
    float p2yUpperLimit = p2y + 150;

    float p2xLowerLimit = p2x - 10;
    float p2xUpperLimit = p2x + 10;

    //I know there is no reason to keep this in memory because we already have the value from p1 but it's less confusing to read this way for a larger project
    // I'd care but for something small like this it doesn't change much
    float p2Width = 20;
    float p2Height = 125;

    float p2Speed = 1200;
    int p2Score = 0;

    //Ball Variables
    float ballx = 400;
    float bally = 200;

    float ballWidth = 20;
    float ballHeight = 20;

    float ballSpeed = 600;
    int ballxDirection = 1;
    int ballyDirection = 1;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        /*player 1 movement : if player is holding W then decrease Y coordinate to make the player 1 paddle go up (this is because the window is essentially in
        the bottom right quadrant of a number plane thus in it's current position decreasing the y value makes the paddle go up)*/ 


        // PLAYER CONTROLS
        if (IsKeyDown(KEY_W))
        {
            p1movementDirection = -1;
            p1y = p1y + p1movementDirection * p1Speed * deltatime;
            if (p1y < 0)
            {
                p1y = 0;
            }
        }
        if (IsKeyDown(KEY_S))
        {
            p1movementDirection = 1;
            p1y = p1y + p1movementDirection * p1Speed * deltatime;
            if (p1y > 325)
            {
                p1y = 325;
            }
        }
        //Player 2 controls
        if (IsKeyDown(KEY_UP))
        {
            p2movementDirection = -1;
            p2y = p2y + p2movementDirection * p2Speed * deltatime;
            if (p2y < 0)
            {
                p2y = 0;
            }
        }
        if (IsKeyDown(KEY_DOWN))
        {
            p2movementDirection = 1;
            p2y = p2y + p2movementDirection * p1Speed * deltatime;
            if (p2y > 325)
            {
                p2y = 325;
            }
        }

        if (IsKeyPressed(KEY_E))
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
        //UPDATE HITBOX BOUNDS
        // update htibox boundary player 1
        p1yLowerLimit = p1y - 10;
        p1yUpperLimit = p1y + 120;
        // update htibox boundary player 2
        p2yLowerLimit = p2y - 10;
        p2yUpperLimit = p2y + 120;

        p1xLowerLimit = p1x - 10;
        p1xUpperLimit = p1x + 10;

        p2xLowerLimit = p2x - 10;
        p2xUpperLimit = p2x + 10;
        
        //BALL PHYSICS AND COLLISION
        //perpetual ball movement
        ballx = ballx + ballxDirection * ballSpeed * deltatime;
        bally = bally + ballyDirection * ballSpeed * deltatime;

        //check ball collision with player 1 paddle
        if (ballx >= p1xLowerLimit && ballx <= p1xUpperLimit && bally >= p1yLowerLimit && bally <= p1yUpperLimit)
        {
            ballxDirection = 1;
            if (p1movementDirection == 1)
            {
                ballyDirection = 1;
            }
            else if (p1movementDirection == -1)
            {
                ballyDirection - 1;
            }
            else
            {
                ballyDirection = 0;
            }
            //increment speed of ball every hit
            ballSpeed = ballSpeed + 50;
        }

        //check ball collision with player 2 paddle
        if (ballx >= p2xLowerLimit && ballx <= p2xUpperLimit && bally >= p2yLowerLimit && bally < p2yUpperLimit)
        {
            ballxDirection = -1;
            if (p2movementDirection == 1)
            {
                ballyDirection = 1;
            }
            else if (p2movementDirection == -1)
            {
                ballyDirection - 1;
            }
            else
            {
                ballyDirection = 0;
            }
            //increment speed of ball every hit
            ballSpeed = ballSpeed + 50;
        }
        //bounce off top and bottom of screen
        //top bounce
        if (bally <= 0)
        {
            ballyDirection = 1;
        }
        //bottom bounce
        if (bally >= 450)
        {
            ballyDirection = -1;
        }

        //check if scored
        if (ballx <= 0)
        {
            p2Score++;
            if (p2Score < 5)
            {
                //reset ball coordinates
                ballx = 400;
                bally = 200;
                //reset ball speed
                ballSpeed = 600;
            }
        }
        //bottom bounce
        if (ballx >= 800)
        {
            p1Score++;
            if (p1Score < 5)
            {
                //reset ball coordinates
                ballx = 400;
                bally = 200;
                //reset ball speed
                ballSpeed = 600;
            }
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
        if (p1Score >= 5)
        {
            p1Score = 5;
        }
        if (p2Score >= 5)
        {
            p2Score = 5;
        }
        std::string p1ScoreText = std::to_string(p1Score);
        std::string p2ScoreText = std::to_string(p2Score);

        //check if a player has won the game
        if (p1Score >= 5)
        {
            DrawText("Player 1 wins!", 250, 200, 56, LIGHTGRAY);
            ballx = 900;
            bally = 200;
            ballSpeed = 0;
        }
        if (p2Score >= 5)
        {
            DrawText("Player 2 wins!", 250, 200, 56, LIGHTGRAY);
            ballx = 0;
            bally = -100;
            ballSpeed = 0;
        }
        //Scoreboard Text
        DrawText(p1ScoreText.c_str(), 350, 20, 80, LIGHTGRAY);
        DrawText("|", 410, 20, 80, LIGHTGRAY);
        DrawText(p2ScoreText.c_str(), 440, 20, 80, LIGHTGRAY);
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}