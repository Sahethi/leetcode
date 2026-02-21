class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, curMax = 0 , curMin = 0, sum = 0;
        for (int i=0; i<nums.length; i++){
            curMax = Math.max(curMax + nums[i], nums[i]);
            curMin = Math.min(curMin + nums[i], nums[i]);
            sum += nums[i];
            max = Math.max(max, curMax);
            min = Math.min(min, curMin);
        }
        if(max > 0){
            return Math.max(max, sum-min);
        } else {
            return max;
        }
    }
}