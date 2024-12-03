#ifndef FOOD_H
#define FOOD_H
#define FOOD_SPAWN_CAP 5

#include "objPos.h"
#include "objPosArrayList.h"
#include <vector>

#define FOOD_SPAWN_CAP 5 // Define max food items

class Food
{
private:
    objPos* foodXYS; // Array of food positions
    int binsize;     // Maximum number of food items
    bool foodoscillator;
    bool specialfood;
    char normalfoodsym;
    char specialfoodsym;

public:
    // Constructors and Destructor
    Food();
    ~Food();
    Food(const Food& food);
    Food& operator=(const Food& food);

    // Food generation
    void generateFood(const objPosArrayList& playpos, int xrange, int yrange);

    // Food retrieval
    objPos getFoodPos(int index) const;
    objPos getFoodPos(int x, int y) const;

    // Oscillator functions
    void switchoscillator();
    bool getfoodoscillator() const;

    // Special food checks
    bool specialfoodcheck();
    char getnormal();
    char getspecial();
};

#endif