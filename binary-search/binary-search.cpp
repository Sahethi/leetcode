class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int low = 0;
        // int high = nums.size()-1;
        // while(low <= high){
        //     int mid = low + (high - low) / 2;

        //     if(target == nums[mid]){
        //         return mid;
        //     } else if(target > nums[mid]) {
        //         low = mid + 1;
        //     } else {
        //         high = mid - 1;
        //     }
        // }
        // return -1;

        auto it = lower_bound(nums.begin(), nums.end(), target);

        if(it != nums.end() && *it == target){
            return it - nums.begin();
        }
        return -1;
    }
};