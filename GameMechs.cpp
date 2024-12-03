#include "GameMechs.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    winFlag = false; // Initialize win flag
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    winFlag = false; // Initialize win flag
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
}

GameMechs::~GameMechs()
{
    // No dynamic memory to free
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

bool GameMechs::getWinFlagStatus() const
{
    return winFlag;
}

void GameMechs::setWinFlag()
{
    winFlag = true;
}

char GameMechs::getInput() const
{
    return input;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore(int currentLength)
{
    score = currentLength - 1;
}