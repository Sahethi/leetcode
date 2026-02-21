class Solution {
    public void moveZeroes(int[] nums) {
        int count=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i] != 0){
                nums[count] = nums[i];
                count++;
            }
        }
        if(count != nums.length-1){
            for(int i=count; i<nums.length; i++){
                nums[i] = 0;
            }
        } else if ( count == nums.length-1){
            nums[count] = 0;
        }

    }
}