//
//  Author: Taylor Bauer
//  Date:   10.24.2019
//          EECS 560
//          Lab 07
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(MinMaxHeap heap) {
    minMax = heap;
}

void Menu::run() {
    cin.clear();
    int selection = 0;
    cout << "\nWelcome!\n";
    while (selection < 10 && selection >= 0) {
        cout << "Please choose one of the following commands:\n"
            << "1. Build Heap\n"
            << "2. Insert\n"
            << "3. Delete\n"
            << "4. Min Level Elements\n"
            << "5. Max Level Elements\n"
            << "6. Exit\n"
            << "Your selection: ";
        cin >> selection;
        if (selection == 1) {
            cout << "Here is the MinMaxHeap:\n";
            minMax.build();
        }
        else if (selection == 2) {
            cout << "What value would you like to insert? (Positive, non-zero integers only please): ";
            int insertion = -1;
            cin >> insertion;
            if (minMax.find(insertion) != 0) {
                cout << insertion << " is already on the queue.  Please try a unique number.\n";
            }
            else {
                minMax.insert(insertion);
                cin.clear();
                cout << "Value " << insertion << " successfully inserted!\n" << endl;
            }            
        }
        else if (selection == 3) {
            cout << "What value would you like to delete? ";
            int deletion = -1;
            cin >> deletion;
            if (!minMax.remove(deletion)) {
                cout << "Unable to delete " << deletion << ". Make sure it is in the heap.\n";
            }
            else {
                cout << "Successfully deleted " << deletion << " from the heap.\n";
            }
        }
        else if (selection == 4) {
            cout << "Here are the Min-Level elements:" << endl;
            minMax.minLevel();
        }
        else if (selection == 5) {
            cout << "Here are the Max-Level elements:" << endl;
            minMax.minLevel();
        }
        else if (selection == 6) {
            cout << "\n\nGoodbye!!!\n\n";
            return;
        }
        else {
            selection = 0;
            cout << "I don't think that's a valid selection, please try again!\n";
        }
    }
}
