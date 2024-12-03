#include "Food.h"
#include <cstdlib>
#include <time.h>
#include <vector>

// Constructor
Food::Food()
{
    binsize = FOOD_SPAWN_CAP; // Maximum number of food items
    foodXYS = new objPos[binsize];
    foodoscillator = true;
    specialfood = false;
    normalfoodsym = 'o';
    specialfoodsym = 'O';
}

// Destructor
Food::~Food()
{
    delete[] foodXYS;
}

// Copy Constructor
Food::Food(const Food& food)
{
    binsize = food.binsize;
    foodXYS = new objPos[binsize];
    for (int i = 0; i < binsize; i++)
    {
        foodXYS[i] = food.foodXYS[i];
    }
    foodoscillator = food.foodoscillator;
    specialfood = food.specialfood;
    normalfoodsym = food.normalfoodsym;
    specialfoodsym = food.specialfoodsym;
}

// Copy Assignment Operator
Food& Food::operator=(const Food& food)
{
    if (this != &food)
    {
        delete[] foodXYS;
        binsize = food.binsize;
        foodXYS = new objPos[binsize];
        for (int i = 0; i < binsize; i++)
        {
            foodXYS[i] = food.foodXYS[i];
        }
        foodoscillator = food.foodoscillator;
        specialfood = food.specialfood;
        normalfoodsym = food.normalfoodsym;
        specialfoodsym = food.specialfoodsym;
    }
    return *this;
}

// Generate Food
void Food::generateFood(const objPosArrayList& playpos, int xrange, int yrange)
{
    srand(time(NULL));

    // Initialize 2D vector to represent availability on the board
    std::vector<std::vector<int> > availablepos(yrange, std::vector<int>(xrange, 0));

    // Mark occupied positions based on the player's current positions
    for (int i = 0; i < playpos.getSize(); i++)
    {
        availablepos[playpos.getElement(i).pos->y][playpos.getElement(i).pos->x] = 1;
    }

    // Generate food items
    for (int i = 0; i < binsize; i++)
    {
        int x, y;
        do
        {
            x = rand() % (xrange - 2) + 1; // Random position within bounds
            y = rand() % (yrange - 2) + 1;
        } while (availablepos[y][x] != 0); // Ensure the position is unoccupied

        // Assign food symbol: Special food for index 3 with a 50% chance
        if (i == 3 && rand() % 2 == 0)
        {
            foodXYS[i].setObjPos(x, y, specialfoodsym);
            specialfood = true;
        }
        else
        {
            foodXYS[i].setObjPos(x, y, normalfoodsym);
        }

        availablepos[y][x] = 1; // Mark position as occupied
    }
}

// Get Food Position by Index
objPos Food::getFoodPos(int index) const
{
    if (index >= 0 && index < binsize)
    {
        return foodXYS[index];
    }
    return objPos(0, 0, ' ');
}

// Get Food Position by Coordinates
objPos Food::getFoodPos(int x, int y) const
{
    for (int i = 0; i < binsize; i++)
    {
        if (foodXYS[i].pos->x == x && foodXYS[i].pos->y == y)
        {
            return foodXYS[i];
        }
    }
    return objPos(0, 0, ' ');
}

// Oscillator Functions
void Food::switchoscillator()
{
    foodoscillator = !foodoscillator;
}

bool Food::getfoodoscillator() const
{
    return foodoscillator;
}

// Check if Food is Special
bool Food::specialfoodcheck()
{
    return specialfood;
}

// Get Normal and Special Symbols
char Food::getnormal()
{
    return normalfoodsym;
}

char Food::getspecial()
{
    return specialfoodsym;
}