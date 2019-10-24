#include <iostream>
#include <fstream>
#include <chrono>
#include "Menu.h"
#include "MinMaxHeap.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "\nPlease make sure you are including a filename in the command line!\n";
        cout << "Ex: ./Lab07 data.txt\n\n";
        return 0;
    }

    fstream myFile;
    myFile.open(argv[1]);

    if (!myFile) {
        cout << "\nError opening file! Please make sure it is a valid file and try again.\n\n";
        return 0;
    }
    else {
        cout << "\nSuccessfully opened file.\n\n";
    }

    int valueCount = 0;
    int currentValue = ' ';
    while (!myFile.eof()){
        myFile >> currentValue;
        valueCount ++;
    }

    myFile.close();
    myFile.open(argv[1]);

    int tempArr[valueCount];
    for (int i; i < valueCount; i++) {
        myFile >> tempArr[i];
    }
    myFile.close();

    MinMaxHeap minMax;

    for (int i; i < valueCount; i++) {
        cout << "inserting " << tempArr[i] << endl;
        minMax.insert(tempArr[i]);
    }
    
    Menu mainMenu(minMax);
    mainMenu.run();

    return 0;
}