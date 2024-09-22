#include <vector>

class MergeSort{

    private:
        std::vector<int> *nums;
    
    public: 
        MergeSort(std::vector<int> *nums){
            this->nums = nums;
        }

        ~MergeSort(){}
        void sort();
        void recursiveSort(int left, int right);

};

void MergeSort::recursiveSort(int left, int right){
    // Change the condition to check if left is greater than right
    if(left >= right){ // Corrected condition
        return;
    }
    int mid = left + (right-left)/2;
    
    recursiveSort(left, mid);
    recursiveSort(mid+1, right);

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
}


void MergeSort::sort(){
    if((*nums).size() ==0 ){
        exit(1);
    }
    recursiveSort(0, (*nums).size()-1);
}