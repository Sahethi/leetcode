class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        
        long long ans = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            long long shifted = (long long)nums[i] << k;

            long long curr=0;

            for(int j=0; j<n; j++){
                if(i==j) curr |= shifted;
                else curr |= nums[j];
            }
            ans = max(ans, curr);
        }

        return ans;
    }
};