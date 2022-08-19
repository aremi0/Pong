/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Title Screen Functions Definitions (Init, Update, Draw, Unload)
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
const char* msg_start = "Premi SPACE per iniziare la partita!";
const char* msg_playerSX = "W\n- \nA";
const char* msg_playerDX = "UP\n- \nDOWN";

//----------------------------------------------------------------------------------
// StartGame Screen Functions Definition
//----------------------------------------------------------------------------------

// StartGame Screen Initialization logic
void InitStartGameScreen(void) {
    // TODO: Initialize StartGame screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// StartGame Screen Update logic
void UpdateStartGameScreen(void) {
    // TODO: Update StartGame screen variables here!

    // Press enter or tap to change to GAMEPLAY screen
    if(IsKeyPressed(KEY_SPACE)) {
        finishScreen = 1;   // GAMEPLAY
        PlaySound(fxCoin);
    }
}

// StartGame Screen Draw logic
void DrawStartGameScreen(Ball* ball, Paddle* sx, Paddle* dx) {
    // TODO: Draw StartGame screen here!

    ClearBackground(BLACK);

    ball->draw();
    sx->draw();
    dx->draw();

    float textWidth = MeasureText(msg_start, 24);
    DrawText(msg_start, GetScreenWidth() / 2.0f - textWidth / 2, GetScreenHeight() / 2.5f , 24, RED);
    DrawText(msg_playerSX, 50, GetScreenHeight() / 7.0f, 16, YELLOW);
    textWidth = MeasureText(msg_playerDX, 16);
    DrawText(msg_playerDX, GetScreenWidth() - 50 - textWidth / 2, GetScreenHeight() / 7.0f, 16, YELLOW);
}

// StartGame Screen Unload logic
void UnloadStartGameScreen(void) {
    // TODO: Unload StartGame screen variables here!
}

// StartGame Screen should finish?
int FinishStartGameScreen(void) {
    return finishScreen;
}