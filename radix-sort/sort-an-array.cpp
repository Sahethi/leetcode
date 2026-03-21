class Solution {
    int partition(vector<int>& nums, int left, int right){
        int pivotIndex = left + rand() % (right - left + 1);
        swap(nums[pivotIndex], nums[right]);
        
        int pivot = nums[right];
        int i = left;

        for(int j=left; j<right; j++){
            if(nums[j] < pivot){
                swap(nums[j], nums[i]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

    void quickSort(vector<int>& nums, int left, int right){
        if(left >= right) return;

        int pivotIndex = partition(nums, left, right);

        quickSort(nums, left, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};