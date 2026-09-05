class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // int n = nums.size();
        // // int j = 1;
        // for(int i=0; i<n; i++){
        //     int j = i+1;
        //     while(j < n && j-i <= k){
        //         if(nums[i] == nums[j])
        //             return true;
        //         j++;
        //     }
        //     // j++;
        // }

        // return false;

        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {

            if (window.count(nums[i]))
                return true;

            window.insert(nums[i]);

            if (window.size() > k)
                window.erase(nums[i - k]);
        }

        return false;
    }
};