#include <iostream>
#include <vector>
#include <mutex>
#include <chrono> // Include chrono for timing
#include "sorting/mergeSort.hpp"
#include "sorting/parallelMergeSort.hpp"

int main(int argc, char *argv[]) {

    const int SIZE = 10000000;
    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        nums[i] = rand() % 10000000;
        nums1[i] = nums[i];
    }

    
    MergeSort* mergesort = new MergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeSortDuration = end - start;

    std::cout << "MergeSort time taken: " << mergeSortDuration.count() << " seconds" << std::endl;

    delete mergesort;

    // Measure time for ParallelMergeSort
    ParallelMergeSort* mergesort1 = new ParallelMergeSort(&nums1);
    start = std::chrono::high_resolution_clock::now();
    mergesort1->sort();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallelMergeSortDuration = end - start;

    std::cout << "ParallelMergeSort time taken: " << parallelMergeSortDuration.count() << " seconds" << std::endl;

    delete mergesort1;

    return 0;
}