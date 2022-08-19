/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Screens Functions Declarations (Init, Update, Draw, Unload)
*
**********************************************************************************************/

#ifndef SCREENS_H
#define SCREENS_H
#include "Ball.h"
#include "Paddle.h"

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef enum GameScreen { DEB = -1, LOGO = 0, STARTGAME, GAMEPLAY, ENDING } GameScreen;

//----------------------------------------------------------------------------------
// Global Variables Declaration (shared by several modules)
//----------------------------------------------------------------------------------
extern GameScreen currentScreen;
extern Font font;
extern Music music;
extern Sound fxCoin;
extern Ball ball;
extern Paddle paddleSX;
extern Paddle paddleDX;
extern const char* winnerText;
extern int playerDxWin;
extern int playerSxWin;


//----------------------------------------------------------------------------------
// Logo Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitLogoScreen(void);
void UpdateLogoScreen(void);
void DrawLogoScreen(void);
void UnloadLogoScreen(void);
int FinishLogoScreen(void);

//----------------------------------------------------------------------------------
// StartGame Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitStartGameScreen(void);
void UpdateStartGameScreen(void);
void DrawStartGameScreen(Ball* ball, Paddle* sx, Paddle* dx);
void UnloadStartGameScreen(void);
int FinishStartGameScreen(void);

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitGameplayScreen(void);
void UpdateGameplayScreen(Ball* ball, Paddle* sx, Paddle* dx);
void DrawGameplayScreen(Ball* ball, Paddle* sx, Paddle* dx);
void UnloadGameplayScreen(void);
int FinishGameplayScreen(void);

//----------------------------------------------------------------------------------
// Ending Screen Functions Declaration
//----------------------------------------------------------------------------------
void InitEndingScreen(void);
void UpdateEndingScreen(Ball* ball, Paddle* sx, Paddle* dx);
void DrawEndingScreen(Ball* ball, Paddle* sx, Paddle* dx);
void UnloadEndingScreen(void);
int FinishEndingScreen(void);


#endif // SCREENS_H