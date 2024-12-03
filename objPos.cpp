#include "objPos.h"

// Default Constructor
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; // NULL
}

// Parameterized Constructor
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Copy Constructor
objPos::objPos(const objPos &a)
{
    pos = new Pos;
    pos->x = a.pos->x;
    pos->y = a.pos->y;
    symbol = a.symbol;
}

// Copy Assignment Operator
objPos& objPos::operator=(const objPos &a)
{
    if (this != &a)
    {
        delete pos; // Avoid memory leak
        pos = new Pos;
        pos->x = a.pos->x;
        pos->y = a.pos->y;
        symbol = a.symbol;
    }
    return *this;
}

// Destructor
objPos::~objPos()
{
    delete pos;
}

// Set Position using another objPos
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

// Set Position using explicit coordinates and symbol
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Get the current position object
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

// Get the symbol of the current position
char objPos::getSymbol() const
{
    return symbol;
}

// Check if this position is equal to another position
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

// Get the symbol if the position matches another position
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if (isPosEqual(refPos))
    {
        return symbol;
    }
    return 0;
}