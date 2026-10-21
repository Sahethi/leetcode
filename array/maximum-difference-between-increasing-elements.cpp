class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1;
        int min = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] <= min){
                min = nums[i];
            }else{
                int diff = nums[i] - min;
                maxDiff = max(maxDiff, diff);
            }
            
        }
        return maxDiff;
    }
};