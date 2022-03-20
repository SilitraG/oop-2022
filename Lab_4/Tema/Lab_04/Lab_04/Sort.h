#pragma once
class Sort
{
    // add data members
    unsigned num_count;
    int* num;
public:
    // add constuctors
    Sort(unsigned num_count, int min, int max);
    Sort(int* vector, unsigned num_count);
    Sort(unsigned num_count, ...);
    Sort(const char* num_string);
    void InsertSort(bool ascendent = false);
    int partitionare(int p, int q);
    void quicksort(int p, int q);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};