#ifndef OBJPOS_H
#define OBJPOS_H

// A simple structure for position
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
public:
    Pos* pos;        
    char symbol;

    // Constructors and Destructor
    objPos();
    objPos(int xPos, int yPos, char sym);
    objPos(const objPos &a);        // Copy Constructor
    objPos& operator=(const objPos &a); // Copy Assignment Operator
    ~objPos();                      // Destructor

    // Methods to manipulate object position
    void setObjPos(objPos o);        
    void setObjPos(int xPos, int yPos, char sym);  

    // Getters
    objPos getObjPos() const;
    char getSymbol() const;
    char getSymbolIfPosEqual(const objPos* refPos) const;

    // Comparison
    bool isPosEqual(const objPos* refPos) const;
};

#endif