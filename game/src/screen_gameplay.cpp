/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"
#include "Ball.h"
#include "Paddle.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(Ball* ball, Paddle* sx, Paddle* dx)
{
    // TODO: Update GAMEPLAY screen variables here!
    ball->move(GetFrameTime());

    if(IsKeyDown(KEY_W))
        sx->move(movement::UP, GetFrameTime());

    if(IsKeyDown(KEY_S))
        sx->move(movement::DOWN, GetFrameTime());

    if(IsKeyDown(KEY_UP))
        dx->move(movement::UP, GetFrameTime());

    if(IsKeyDown(KEY_DOWN))
        dx->move(movement::DOWN, GetFrameTime());

    // Verifico se c'è collisione con player Paddle
    ball->checkCollisions(sx->getRect(), dx->getRect(), fxCoin);
    winnerText = ball->handleWinner(playerDxWin, playerSxWin);


    // Change to ENDING screen
    if(winnerText) 
        finishScreen = 2;

}

// Gameplay Screen Draw logic
void DrawGameplayScreen(Ball* ball, Paddle* sx, Paddle* dx)
{
    // TODO: Draw GAMEPLAY screen here!

    ClearBackground(BLACK);

    ball->draw();
    sx->draw();
    dx->draw();

    DrawFPS(10, 10);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}