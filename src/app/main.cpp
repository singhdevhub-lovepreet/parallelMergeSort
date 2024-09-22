#include <iostream>
#include "sorting/mergeSort.cpp"
#include "sorting/parallelMergeSort.cpp"
#include <vector>

int main(int argc, char *argv[]){

    std::vector<int> nums = {5,2,1,10,8,7};
    MergeSort* mergesort = new MergeSort(&nums);

    mergesort->sort();

    std::cout<<"sorted array is: "<<std::endl;
    for(int i = 0; i<nums.size(); i++){
        std::cout<<nums[i]<<std::endl;
    }

    delete mergesort;


    std::vector<int> nums1 = {5,2,1,10,8,7};
    ParallelMergeSort* mergesort1 = new ParallelMergeSort(&nums1);

    mergesort1->sort();

    std::cout<<"sorted array is: "<<std::endl;
    for(int i = 0; i<nums1.size(); i++){
        std::cout<<nums1[i]<<std::endl;
    }

    delete mergesort1;

}