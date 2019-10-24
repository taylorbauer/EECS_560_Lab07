//
//  Author: Taylor Bauer
//  Date:   10.24.2019
//          EECS 560
//          Lab 07
//

#ifndef MIN_MAX_HEAP
#define MIN_MAX_HEAP

class MinMaxHeap {
    public:

        //  Basic constructor.  Sets size to 0 and fills the array with the value '-1'
        MinMaxHeap();

        //  Inserts the value on the minmax heap
        //  Throws an error if it is a duplicate value
        void insert(int value);

        //  Prints out the heap, starting with the root node
        void build();

        //  Same as build, but only prints the min levels
        void minLevel();

        //  Same as build, but only prints the max levels
        void maxLevel();

        //  Searches for the value.  Mostly a helper function.
        //  Returns the index of the value, or 0 if it cannot be found
        int find(int value);

        //  Removes the indicated value
        //  Returns true if the value is found and deleted, false otherwise.
        bool remove(int value);
    private:

        //  The array that represents a min-max heap.  Right now it is set to 1000, but there is no reason why it couldn't be more
        //  The 0 index is empty to make calculations less messy
        int arr[1000];

        //  The size of the array.  With indexing starting at 1, the last value is conveniently at arr[size]
        int size;

        //  Heapifies the heap, going upwards
        //  This is used in insertion
        void heapify(int index);

        //  Heapifies the heap, going downwards
        //  This is used in deletion
        void heapifyDown(int index);

        //  Returns true if the index indicated is on a min level.  False otherwise.
        bool isMin(int index);

        //  Swaps the two indicated indexes
        //  Agnostic as to weather these exist on the array, so the caller must be careful.
        void swap(int first, int second);
};

#endif