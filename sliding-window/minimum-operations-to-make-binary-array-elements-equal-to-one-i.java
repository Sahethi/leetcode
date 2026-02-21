class Solution {
    public int minOperations(int[] nums) {
        
        int count = 0;
        int len = nums.length;
        for(int i=0; i <= len - 3 ; i++){
            if(nums[i] == 0){
                nums[i] = (nums[i] == 1) ? 0 : 1;
                nums[i+1] = (nums[i+1] == 1) ? 0 : 1;
                nums[i+2] = (nums[i+2] == 1) ? 0 : 1;
                count++;
            }
        }
        return (nums[len-1] == 0 || nums[len-2] == 0) ? -1 : count;
    }
}