class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int prefixSum = 0;
        unordered_map<int, int> count;
        count[0] = 1;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            
            if(count[prefixSum - k] > 0){
                ans += count[prefixSum - k];
            }
            count[prefixSum]++;
        }
        return ans;
    }
};