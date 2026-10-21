class Solution {
public:
    //greedy and binary search
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for(int n : nums){
            //fins the element that is tails[i] >= n
            auto it = lower_bound(tails.begin(), tails.end(), n);

            //n is bigger than all values in tails
            if(it == tails.end()){
                tails.push_back(n);
            }else{
                //replace tails[i] with x
                *it = n;
            }
        }
        return tails.size();
    }

    //dynamic progamming
    /*
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        //basically dp[i] is storing the max length before i, 
        //and j cover all the incides before hitting i
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    */
};