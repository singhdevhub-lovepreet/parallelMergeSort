#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

class ParallelMergeSort {
private:
    std::vector<int> *nums;

public:
    ParallelMergeSort(std::vector<int> *nums);
    ~ParallelMergeSort();
    void sort();
    void recursiveSort(int left, int right);
};

#endif