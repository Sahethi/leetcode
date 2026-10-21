class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0, mid = 0, high=nums.size()-1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }

        /**
        const int OFFSET = 50000;
        const int SIZE = 100001;

        vector<int> count(SIZE, 0);

        for(int n : nums){
            count[n + OFFSET]++;
        }

        int idx=0;
        for(int i=0; i<SIZE; i++){
            while(count[i] > 0){
                nums[idx++] = i - OFFSET;
                count[i]--;
            }
        }
        **/

    }
};