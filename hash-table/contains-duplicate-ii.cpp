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

        unordered_map<int,int> lastIndex;
        //storing the number and the index 

        int n = nums.size();
        for(int i=0; i<n; i++){
            if(lastIndex.count(nums[i])){
                if(i - lastIndex[nums[i]] <= k)
                    return true;
            }

            lastIndex[nums[i]] = i;
        }
        return false;
    }
};