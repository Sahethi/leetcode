class Solution {
public:
    bool isGood(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i=0; i<n-1; i++){
            if(nums[i] != i+1) return false;
        }

        if(nums[n-1] != n-1) return false;

        return true;
        
        
        // int n = *max_element(nums.begin(), nums.end());

        // if(nums.size() != n+1){
        //     return false;
        // }

        // vector<int> freq(n+1, 0);

        // for(int i : nums){
        //     freq[i]++;
        // }

        // if(freq[n] != 2) return false;

        // for(int i=1; i<n; i++){
        //     if(freq[i] != 1) return false;
        // }
        
        // return true;

    }
};