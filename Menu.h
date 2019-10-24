//
//  Author: Taylor Bauer
//  Date:   10.24.2019
//          EECS 560
//          Lab 07
//

#ifndef MENU_H
#define MENU_H
#include "MinMaxHeap.h"

//  The class that handles all user interaction and manages the heap
class Menu {
public:

    // Constructor that requires a pre-existing heap
    Menu(MinMaxHeap heap);

    //  Run the menu.  This is where all user interaction takes place.
    void run();
private:
    MinMaxHeap minMax;
};

#endif