#include <vector>
#include <thread>
#include <mutex>

class ParallelMergeSort{

    private:
        std::vector<int> *nums;
        std::mutex(sorting_lock);
    
    public: 
        ParallelMergeSort(std::vector<int> *nums){
            this->nums = nums;
        }

        ~ParallelMergeSort(){}
        void sort();
        void recursiveSort(int left, int right);

};

void ParallelMergeSort::recursiveSort(int left, int right){
    // Change the condition to check if left is greater than right
    std::unique_lock<std::mutex> lock(sorting_lock);
    if(left >= right){ // Corrected condition
        return;
    }
    int mid = left + (right-left)/2;

    std::thread thread_1([this, left, mid] { recursiveSort(left, mid); });
    std::thread thread_2([this, mid, right] { recursiveSort(mid+1, right); });
    thread_1.join();
    thread_2.join();

    std::vector<int> result;
    
    int i = left;
    int j = mid + 1; // Corrected to start j from mid + 1
    
    while(i <= mid && j <= right){
        if((*nums)[i] <= (*nums)[j]){ // Corrected to dereference nums
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    // Add remaining elements from left half
    while(i <= mid){
        result.push_back((*nums)[i]);
        i++;
    }

    // Add remaining elements from right half
    while(j <= right){
        result.push_back((*nums)[j]);
        j++;
    }
    
    // Copy sorted elements back to the original vector
    for(int k = 0; k < result.size(); k++){
        (*nums)[left + k] = result[k];
    }
    lock.unlock();
}


void ParallelMergeSort::sort(){
    if((*nums).size() ==0 ){
        exit(1);
    }

    std::thread thread_1([this] { recursiveSort(0, (*nums).size() - 1); });
    thread_1.join();
}