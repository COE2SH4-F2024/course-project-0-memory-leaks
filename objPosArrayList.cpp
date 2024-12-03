#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

// Default Constructor
objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;        // Set maximum capacity
    listSize = 0;                         // Initialize size to 0
    aList = new objPos[arrayCapacity];    // Allocate memory for the array
}

// Destructor
objPosArrayList::~objPosArrayList()
{
    delete[] aList;                       // Free allocated memory
}

// Copy Constructor
objPosArrayList::objPosArrayList(const objPosArrayList& array)
{
    arrayCapacity = ARRAY_MAX_CAP;        // Set maximum capacity
    listSize = array.getSize();           // Copy the size
    aList = new objPos[arrayCapacity];    // Allocate memory for the new array
    for (int i = 0; i < listSize; i++)
    {
        aList[i] = array.aList[i];        // Copy each element
    }
}

// Copy Assignment Operator
objPosArrayList& objPosArrayList::operator=(const objPosArrayList& array)
{
    if (this != &array)                   // Prevent self-assignment
    {
        this->listSize = array.getSize(); // Copy the size
        for (int i = 0; i < this->listSize; i++)
        {
            this->aList[i] = array.aList[i]; // Copy each element
        }
    }
    return *this;
}

// Get the current size of the list
int objPosArrayList::getSize() const
{
    return listSize;
}

// Insert an element at the head of the list
void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize >= arrayCapacity) return; // Do nothing if the list is full

    // Shift all elements to the right to make space at the head
    for (int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i - 1];
    }
    aList[0] = thisPos;                    // Add the new element at the head
    listSize++;                            // Increment the size
}

// Insert an element at the tail of the list
void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity) return; // Do nothing if the list is full

    aList[listSize] = thisPos;             // Add the new element at the end
    //listSize++;                            // Increment the size
}

// Remove the head element of the list
void objPosArrayList::removeHead()
{
    if (listSize == 0) return;             // Do nothing if the list is empty

    // Shift all elements to the left to remove the head
    for (int i = 0; i < listSize - 1; i++)
    {
        aList[i] = aList[i + 1];
    }
    listSize--;                            // Decrease the size
}

// Remove the tail element of the list
void objPosArrayList::removeTail()
{
    if (listSize == 0) return;             // Do nothing if the list is empty
    listSize--;                            // Simply decrease the size
}

// Get the head element of the list
objPos objPosArrayList::getHeadElement() const
{
    return aList[0];                       // Return the first element
}

// Get the tail element of the list
objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];            // Return the last element
}

// Get an element at a specific index
objPos objPosArrayList::getElement(int index) const
{
    if (listSize == 0)                     // If the list is empty, return the first element
    {
        return aList[0];
    }
    else if (index < 0)                    // If index is less than 0, use 0
    {
        index = 0;
    }
    else if (index >= listSize)            // If index exceeds the size, use the last index
    {
        index = listSize - 1;
    }

    return aList[index];                   // Return the element at the specified index
}