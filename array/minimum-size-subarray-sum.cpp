class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0, left = 0, windowSize = INT_MAX;
        
        for(int right=0; right<nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                windowSize = min(windowSize, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return windowSize == INT_MAX ? 0 : windowSize;
    }
};