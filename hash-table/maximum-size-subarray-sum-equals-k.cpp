class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {

        long long maxLen = 0;
        unordered_map<long long, long long> prefixIdx;
        long long prefixSum = 0;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            if(prefixSum == k){
                maxLen = i+1;
            }
            if(prefixIdx.find(prefixSum - k) != prefixIdx.end()){
                maxLen = max(maxLen, i - prefixIdx[prefixSum - k]);
            }
            if (prefixIdx.find(prefixSum) == prefixIdx.end()) {
                prefixIdx[prefixSum] = i;
            }
        }

        return maxLen;
    }
};