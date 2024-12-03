#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

// Global Variables
GameMechs* gameMechanics;
Food* food;
Player* player;
bool exitFlag;

// Function Prototypes
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void)
{
    Initialize();

    // Main game loop
    while (!exitFlag && !gameMechanics->getLoseFlagStatus() && !gameMechanics->getWinFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    // CleanUp();
    return 0;
}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    // Initialize game components
    gameMechanics = new GameMechs(15, 30); // Board size: 15x30
    food = new Food();
    player = new Player(gameMechanics, food);

    // Generate initial food
    food->generateFood(*player->getPlayerPos(), gameMechanics->getBoardSizeX(), gameMechanics->getBoardSizeY());

    exitFlag = false;
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        // Get input and update direction
        gameMechanics->setInput(MacUILib_getChar());
        player->updatePlayerDir();
        gameMechanics->clearInput();
    }
}

void RunLogic(void)
{
    // Move player and handle game logic
    player->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // Create board array
    char board[gameMechanics->getBoardSizeX()][gameMechanics->getBoardSizeY()];
    for (int i = 0; i < gameMechanics->getBoardSizeX(); i++)
    {
        for (int j = 0; j < gameMechanics->getBoardSizeY(); j++)
        {
            // Draw borders
            if (i == 0 || i == gameMechanics->getBoardSizeX() - 1 || j == 0 || j == gameMechanics->getBoardSizeY() - 1)
            {
                board[i][j] = '#';
            }
            else
            {
                board[i][j] = ' '; // Empty space
            }

            // Draw player
            for (int k = 0; k < player->getPlayerPos()->getSize(); k++)
            {
                if (i == player->getPlayerPos()->getElement(k).pos->x && j == player->getPlayerPos()->getElement(k).pos->y)
                {
                    board[i][j] = player->getPlayerPos()->getElement(k).symbol;
                }
            }

            // Draw food
            for (int k = 0; k < FOOD_SPAWN_CAP; k++)
            {
                if (i == food->getFoodPos(k).pos->x && j == food->getFoodPos(k).pos->y)
                {
                    // Oscillate special food
                    if (k == 3 && food->specialfoodcheck())
                    {
                        if (food->getfoodoscillator())
                        {
                            board[i][j] = food->getspecial();
                            food->switchoscillator();
                        }
                        else
                        {
                            board[i][j] = food->getnormal();
                            food->switchoscillator();
                        }
                    }
                    else
                    {
                        board[i][j] = food->getFoodPos(k).getSymbol();
                    }
                }
            }
            MacUILib_printf("%c", board[i][j]); // Print the board
        }
        MacUILib_printf("\n");
    }

    // Display messages
    if (!gameMechanics->getLoseFlagStatus() && !gameMechanics->getExitFlagStatus() && !gameMechanics->getWinFlagStatus())
    {
        MacUILib_printf("Score: %d\n", gameMechanics->getScore());
        MacUILib_printf("Use 'W', 'A', 'S', 'D' to move the snake.\n");
        MacUILib_printf("Special food blinks and gives extra points!\n");
    }
    else if (gameMechanics->getLoseFlagStatus())
    {
        MacUILib_printf("Game Over! You lost. Final score: %d\n", gameMechanics->getScore());
    }
    else if (gameMechanics->getWinFlagStatus())
    {
        MacUILib_printf("Congratulations! You won the game.\n");
        MacUILib_printf("Final score: %d\n", gameMechanics->getScore());
    }
    else if (gameMechanics->getExitFlagStatus())
    {
        MacUILib_printf("You exited the game. See you next time!\n", gameMechanics->getScore());
    }
}

void LoopDelay(void)
{
    // Delay adjusted by player speed
    MacUILib_Delay(DELAY_CONST / player->getSpeed());
}

void CleanUp(void)
{
    // Free resources
    delete gameMechanics;
    delete food;
    delete player;

    MacUILib_clearScreen();
    MacUILib_uninit();
}