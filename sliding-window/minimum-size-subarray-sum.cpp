class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0;
        int left = 0;
        int windowSize = 0;
        for(int right=0; right<nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                sum -= nums[left];
                left++;
            }
            windowSize = right - left + 1;
        }

        return windowSize;
    }
};