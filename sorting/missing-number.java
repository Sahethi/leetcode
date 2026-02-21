class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int res = nums.length; //considering last number
        //xor with yourself is 0, and xor with 0 is 1
        for(int i=0; i<n; i++){
            res = res ^ nums[i] ^ i;
        }
        return res;
    }
}