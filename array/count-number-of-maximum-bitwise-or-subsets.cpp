class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //simple idea is generate every subset and check its OR
        //we are only interested in non empty subset
        /**
        [3,1]
        [] [1] [3] [3,1]
        max is 3 therefore the answer is [3] and[3,1]
        so 2

        max or is max of all elements in array
        **/

        int maxOR = 0;
        int n = nums.size();
        for(int n : nums){
            maxOR |= n;
        }
        //now we have to find how many subsets do have the maxOR 
        //to generate every subset thats like 2^n 
        //we can represent each subset with the help of a bitmask
        int ans = 0;
        for(int mask=1; mask < (1 << n); mask++){
            int currOR = 0;

            for(int i=0; i<n; i++){
                if((mask >> i) & 1){
                    currOR |= nums[i];
                }
            }
            if(currOR == maxOR) ans++;
        }

        return ans;
    }
};