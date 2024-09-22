#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort {
private:
    std::vector<int> *nums;

public:
    MergeSort(std::vector<int> *nums);
    ~MergeSort();
    void sort();
    void recursiveSort(int left, int right);
};

#endif