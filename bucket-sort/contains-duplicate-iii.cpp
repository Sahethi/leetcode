class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> window;

        for(int i=0; i<nums.size(); i++){
            
            if(i > indexDiff){
                window.erase(nums[i-indexDiff-1]);
            }
            auto it = window.lower_bound(nums[i] - valueDiff);
            if(it != window.end() && *it <= nums[i] + valueDiff){
                return true;
            }

            window.insert(nums[i]);
        }
        return false;
    }
};