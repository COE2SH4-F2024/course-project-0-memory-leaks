#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs
{
private:
    char input;
    bool exitFlag;
    bool loseFlag;
    bool winFlag;  // New win flag
    int score;

    int boardSizeX;
    int boardSizeY;

public:
    GameMechs();
    GameMechs(int boardX, int boardY);
    ~GameMechs(); // Destructor

    bool getExitFlagStatus() const;
    void setExitTrue();
    bool getLoseFlagStatus() const;
    void setLoseFlag();
    bool getWinFlagStatus() const; // Getter for win flag
    void setWinFlag();             // Setter for win flag

    char getInput() const;
    void setInput(char this_input);
    void clearInput();

    int getBoardSizeX() const;
    int getBoardSizeY() const;

    int getScore() const;
    void incrementScore(int currentLength);
};

#endif