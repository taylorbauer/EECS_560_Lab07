#ifndef MENU_H
#define MENU_H
#include "MinMaxHeap.h"

//  The class that handles all user interaction and manages the two heaps
class Menu {
public:

    Menu(MinMaxHeap heap);

    //  Run the menu.  This is where all user interaction takes place.
    void run();
private:
    MinMaxHeap minMax;
};

#endif