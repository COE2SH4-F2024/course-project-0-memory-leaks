#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
private:
    objPos* aList;       // Dynamic array to hold objPos objects
    int listSize;        // Current number of elements in the list
    int arrayCapacity;   // Maximum capacity of the array

public:
    // Constructors and Destructor
    objPosArrayList();                          // Default Constructor
    ~objPosArrayList();                         // Destructor
    objPosArrayList(const objPosArrayList& array); // Copy Constructor
    objPosArrayList& operator=(const objPosArrayList& array); // Copy Assignment Operator

    // Getters
    int getSize() const;

    // Insertions
    void insertHead(objPos thisPos);
    void insertTail(objPos thisPos);

    // Removals
    void removeHead();
    void removeTail();

    // Accessors
    objPos getHeadElement() const;
    objPos getTailElement() const;
    objPos getElement(int index) const;
};

#endif