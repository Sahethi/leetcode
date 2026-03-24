class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {

        int maxLen = 0;
        unordered_map<int, int> prefixIdx;
        int prefixSum = 0;

        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            if(prefixSum == k){
                maxLen = i+1;
            }
            if(prefixIdx.find(prefixSum - k) != prefixIdx.end()){
                maxLen = max(maxLen, i - prefixIdx[prefixSum - k]);
            } else if (prefixIdx.find(prefixSum-k) == prefixIdx.end()) {
                prefixIdx[prefixSum] = i;
            }
        }

        return maxLen;
    }
};