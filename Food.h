#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>
#include <vector>
#include "objPos.h"
#include "objPosArrayList.h"

// Define the maximum number of food items
#define FOOD_SPAWN_CAP 5

class Food
{
private:
    objPos* foodXYS;       // Array of food positions
    int binsize;           // Number of food items
    bool foodoscillator;   // Toggle for special food display
    bool specialfood;      // Indicates special food availability
    char normalfoodsym;    // Symbol for normal food
    char specialfoodsym;   // Symbol for special food

public:
    // Constructors and Destructor
    Food();
    ~Food();
    Food(const Food& food);              // Copy Constructor
    Food& operator=(const Food& food);   // Copy Assignment Operator

    // Generate food items
    void generateFood(objPosArrayList playpos, int xrange, int yrange);

    // Get food positions
    objPos getFoodPos(int index) const;
    objPos getFoodPos(int x, int y) const;

    // Oscillator control
    void switchoscillator();
    bool getfoodoscillator() const;

    // Special food checks
    bool specialfoodcheck();
    char getnormal();
    char getspecial();
};

#endif