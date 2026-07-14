class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        
        // long long ans = INT_MIN;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     long long shifted = (long long)nums[i] << k;

        //     long long curr=0;

        //     for(int j=0; j<n; j++){
        //         if(i==j) curr |= shifted;
        //         else curr |= nums[j];
        //     }
        //     ans = max(ans, curr);
        // }

        // return ans;

        int n = nums.size();

        vector<long long> prefix(n);
        vector<long long> suffix(n);

        // Build prefix OR
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] | nums[i];
        }

        // Build suffix OR
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] | nums[i];
        }

        long long ans = 0;

        // Try shifting each element
        for (int i = 0; i < n; i++) {

            long long left = (i == 0) ? 0 : prefix[i - 1];
            long long right = (i == n - 1) ? 0 : suffix[i + 1];

            long long shifted = (long long)nums[i] << k;

            long long curr = left | shifted | right;

            ans = max(ans, curr);
        }

        return ans;
    }
};