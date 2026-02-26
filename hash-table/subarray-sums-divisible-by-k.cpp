class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k, 0);
        int prefixSum = 0;
        int ans = 0;
        count[0] = 1;
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            int r = prefixSum % k;
            if(r < 0) r += k;
            ans += count[r];
            count[r]++;
        }

        return ans;
    }
};