//
//  Author: Taylor Bauer
//  Date:   10.24.2019
//          EECS 560
//          Lab 07
//

#include <iostream>
#include <cmath>
#include "MinMaxHeap.h"

using namespace std;

MinMaxHeap::MinMaxHeap() {
    for (int i = 0; i < 1000; i++) {
        arr[i] = -1;
    }
    size = 0;
}

//  inserts value at size + 1
//  this keeps the standard of starting the array at 1
void MinMaxHeap::insert(int value) {
    size ++;
    arr[size] = value;
    if (size == 1) {
        return;
    }
    else {
        heapify(size);
    }
}

void MinMaxHeap::heapify(int index) {
    int parentIndex = (index / 2);
    int grandparentIndex = parentIndex / 2;

    if (index == 1) {
        return;
    }
    //  If parent is on a min level
    if (isMin(parentIndex)) {
        if (arr[index] < arr[parentIndex]) {
            swap(index, parentIndex);
            heapify(parentIndex);
        }
        else if (grandparentIndex != 0) {
            if (arr[index] > arr[grandparentIndex]) {
                swap(index, grandparentIndex);
                heapify(grandparentIndex);
            }
        }
    }

    //  If parent is on a max level
    else {
        if (arr[index] > arr[parentIndex]) {
            swap(index, parentIndex);
            heapify(parentIndex);
        }
        else if (grandparentIndex != 0) {
            if (arr[index] < arr[grandparentIndex]) {
                swap(index, grandparentIndex);
                heapify(grandparentIndex);
            }
        }
    }
}

void MinMaxHeap::swap(int first, int second) {
    cout << "\nSWAPPING " << arr[first] << " AND " << arr[second] << endl;
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
    return;
}

bool MinMaxHeap::isMin(int index){
    if (index == 1) {
        return true;
    }
    else if (index == 2 || index == 3) {
        return false;
    }
    else {
        return !(isMin(index / 2));
    }
}

void MinMaxHeap::build() {
    for (int i = 1; i <= size; i ++) {
        cout << arr[i] << ", ";
        if ((ceil(log2(i + 1)) == floor(log2(i + 1)))) {  //if i is a power of 2, we need to make a new line
            // cout << endl << endl << "I THINK I JUST PRINTED POSITION " << i << endl;
            cout << endl;
        }
    }
    cout << endl << endl;
}

void MinMaxHeap::minLevel() {
    for (int i = 1; i <= size; i ++) {
        if (isMin(i)){
            cout << arr[i] << ", ";
        }
        if ((ceil(log2(i + 1)) == floor(log2(i + 1)))) {  //if i is a power of 2, we need to make a new line
            // cout << endl << endl << "I THINK I JUST PRINTED POSITION " << i << endl;
            cout << endl;
        }
    }
}

void MinMaxHeap::maxLevel() {
    for (int i = 1; i <= size; i ++) {
        if (!(isMin(i))){
            cout << arr[i] << ", ";
        }
        if ((ceil(log2(i + 1)) == floor(log2(i + 1)))) {  //if i is a power of 2, we need to make a new line
            // cout << endl << endl << "I THINK I JUST PRINTED POSITION " << i << endl;
            cout << endl;
        }
    }
}

int MinMaxHeap::find(int value) {
    for (int i = 1; i <= size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return (0);
}

bool MinMaxHeap::remove(int value) {
    int index = find(value);
    if (index == 0) {
        return false;
    }
    else {
        arr[index] = -1;
        swap(index, size);
        size --;
        heapifyDown(index);
        return true;
    }
}

void MinMaxHeap::heapifyDown(int index) {
    int firstChildIndex = index * 2;
    int firstGrandchildIndex = firstChildIndex * 2;
    if (firstChildIndex > size) {
        return;
    }
    //  When node has only 1 child
    else if (firstChildIndex + 1 > size) {

        //if node is on a min row
        if (isMin(index)) {
            if (arr[firstChildIndex] < arr[index]) {
                swap(index, firstChildIndex);
                return;
            }
        }

        //if node is on a max row
        else {
            if (arr[firstChildIndex] > arr[index]) {
                swap(index, firstChildIndex);
                return;
            }
        }
    }

    int grandchildrenCount = 0;  
    for (int i = 0; i < 4; i++) {
    if ((firstGrandchildIndex + i < size)) {
        grandchildrenCount ++;
        }
    }
    if (grandchildrenCount == 0) {
        if (isMin(index)) {
        if (arr[firstChildIndex] < arr[index] || arr[firstChildIndex + 1] < arr[index]) {
            if (arr[firstChildIndex < arr[firstChildIndex + 1]]) {  //if the left child is smaller
                swap(index, firstChildIndex);
                heapifyDown(firstChildIndex);
                return;
            }
            else {                                                  //if the right child is smaller
                swap(index, firstChildIndex + 1);
                heapifyDown(firstChildIndex + 1);
                return;
            }
        }
    }
        //if the node is on a max row
        else {
            if (arr[firstChildIndex] > arr[index] || arr[firstChildIndex + 1] > arr[index]) {
                if (arr[firstChildIndex > arr[firstChildIndex + 1]]) {  //if the left child is larger
                    swap(index, firstChildIndex);
                    heapifyDown(firstChildIndex);
                    return;
                }
                else {                                                  //if the right child is larger
                    swap(index, firstChildIndex + 1);
                    heapifyDown(firstChildIndex + 1);
                    return;
                }
            }            
        }
        }

        //  Looping through grandchildren if it is a min node
        else if (isMin(index)){
            int smallestGrandchildIndex = 0;
            for (int i = 0; i < grandchildrenCount; i++) {
                if (arr[firstGrandchildIndex + i] < arr[index]) {
                    if (smallestGrandchildIndex == 0 || arr[firstGrandchildIndex + i] < arr[smallestGrandchildIndex]) {
                        smallestGrandchildIndex = firstGrandchildIndex + i;
                    }
                }
            }
            if (smallestGrandchildIndex != 0) {
                swap(index, smallestGrandchildIndex);
                heapifyDown(firstGrandchildIndex);
                return;
            }
        }

        //  Looping through grandchildren if it is a max node
        else {
            int largestGrandchildIndex = 0;
            for (int i = 0; i < grandchildrenCount; i++) {
                if (arr[firstGrandchildIndex + i] > arr[index]) {
                    if (largestGrandchildIndex == 0 || arr[firstGrandchildIndex + i] > arr[largestGrandchildIndex]) {
                        largestGrandchildIndex = firstGrandchildIndex + i;
                    }
                }
            }
            if (largestGrandchildIndex != 0) {
                swap(index, largestGrandchildIndex);
                heapifyDown(firstGrandchildIndex);
                return;
            }
        }


    }
