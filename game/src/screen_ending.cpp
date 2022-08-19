/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Ending Screen Functions Definitions (Init, Update, Draw, Unload)
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
#include "Italian.h"
#include <string>


//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
const char* msg_restart = "Premi SPACE per iniziare una nuova partita!";

//----------------------------------------------------------------------------------
// Ending Screen Functions Definition
//----------------------------------------------------------------------------------

// Ending Screen Initialization logic
void InitEndingScreen(void)
{
    // TODO: Initialize ENDING screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Ending Screen Update logic
void UpdateEndingScreen(Ball* ball, Paddle* sx, Paddle* dx)
{
    // TODO: Update ENDING screen variables here!

    // Sono nella schermata END-SCREEN e premo "spazio" => ricomincio il gioco
    if (IsKeyPressed(KEY_SPACE))
    {
        finishScreen = 1;
        PlaySound(fxCoin);
        winnerText = nullptr; // Premuto "spazio" resetto winner
    }

    //Resetto gli oggetti sullo schermo (costruttore)
    *ball = Ball(GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, 5.0f);
    *sx = Paddle(50, GetScreenHeight() / 2);
    *dx = Paddle(GetScreenWidth() - 50, GetScreenHeight() / 2);
}

// Ending Screen Draw logic
void DrawEndingScreen(Ball* ball, Paddle* sx, Paddle* dx)
{
    ClearBackground(BLACK);

    float textWidth = MeasureText(winnerText, 24);
    DrawText(winnerText, GetScreenWidth() / 2.0f - textWidth / 2, GetScreenHeight() / 2.0f + 10, 24, DARKPURPLE);
    textWidth = MeasureText(msg_restart, 18);
    DrawText(msg_restart, GetScreenWidth() / 2.0f - textWidth / 2, GetScreenHeight() / 1.7f, 18, RED);

    std::string str = std::to_string(playerSxWin);
    DrawText(str.c_str(), 50, GetScreenHeight() / 7.0f, 20, YELLOW);

    str = std::to_string(playerDxWin);
    DrawText(str.c_str(), GetScreenWidth() - 130 / 2, GetScreenHeight() / 7.0f, 20, YELLOW);

}

// Ending Screen Unload logic
void UnloadEndingScreen(void)
{
    // TODO: Unload ENDING screen variables here!
}

// Ending Screen should finish?
int FinishEndingScreen(void)
{
    return finishScreen;
}