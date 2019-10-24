#ifndef MIN_MAX_HEAP
#define MIN_MAX_HEAP

class MinMaxHeap {
    public:
        MinMaxHeap();
        void insert(int value);
        void build();
        void minLevel();
        void maxLevel();
        int find(int value);
        bool remove(int value);
    private:
        int arr[1000];
        int size;
        void heapify(int index);
        void heapifyDown(int index);
        bool isMin(int index);
        void swap(int first, int second);
};

#endif