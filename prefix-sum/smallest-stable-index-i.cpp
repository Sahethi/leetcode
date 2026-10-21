class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        /**
        for each i 
            find max from 0 to i
            find min from i to n-1

            if max - min <= k 
                return i 
        **/
        int n = nums.size();
        //suffixMin[i] = minimum value from nums[i] to nums[n-1]
        vector<int> suffixMin(n);
        suffixMin[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            suffixMin[i] = min(nums[i], suffixMin[i+1]);
        }

        int prefixMax = nums[0];

        for(int i=0; i<n; i++){
            prefixMax = max(prefixMax, nums[i]);

            if(prefixMax - suffixMin[i] <= k) return i;
        }

        return -1;
    }
};