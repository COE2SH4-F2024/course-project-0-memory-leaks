#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"
#include <iostream>

class Player
{   
public:
    enum Dir { UP, DOWN, LEFT, RIGHT, STOP }; // Direction state

    // Constructors and Destructor
    Player(); 
    Player(GameMechs* thisGMRef, Food* thisFood);
    ~Player();
    Player(const Player& pp);                // Copy constructor
    Player& operator=(const Player& pp);     // Copy assignment operator

    // Player Movement and Behavior
    objPosArrayList* getPlayerPos() const;      
    void updatePlayerDir();
    void movePlayer();
    bool checkFoodConsumption(); 
    void increasePlayerLength();
    bool checkselfcollision();

    // Speed Control
    int getSpeed() const; 
    void setSpeed(int s);        

    // Food Management
    Food* getFoodlist() const;

private:
    objPosArrayList* player;  // Snake body positions
    char headsymbol;          // Symbol for the head
    char bodysymbol;          // Symbol for the body
    enum Dir myDir;           // Current direction

    Food* foodlist;           // Reference to the food object
    GameMechs* mainGameMechsRef; // Reference to game mechanics

    int rowNums;              // Number of rows (board height)
    int colNums;              // Number of columns (board width)
    int speed;                // Speed of the snake
};

#endif