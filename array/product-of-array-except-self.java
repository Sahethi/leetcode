class Solution {
    public int[] productExceptSelf(int[] nums) {
        int left = 1;
        int right = 1;
        int arr[] = new int[nums.length];
        //left
        for(int i=0; i< nums.length; i++){
            if( i > 0)
                left *= nums[i-1];
            arr[i] = left;
        }
        //right
        for(int i=nums.length-1; i>=0; i--){
            if(i < nums.length-1)
                right *= nums[i+1];
            arr[i] *= right;
        }
        // for(i = 0; i < nums.length; i++){
        //     for(int j=0; j<i; j++){
        //         prod *= nums[j];
        //     }
        //     for(int j=nums.length -1; j > i; j--){
        //         prod *= nums[j];
        //     }
        //     arr[i] = prod;
        //     prod = 1;
        // }
        return arr;
    }
}