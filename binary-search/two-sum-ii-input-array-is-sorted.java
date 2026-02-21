class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int sum = 0;
        int left = 0;
        int right = numbers.length - 1;

        while(left < right){
            sum = numbers[left] + numbers[right];
            if(sum < target)
                left++;
            else if(sum > target)
                right--;
            else
                return new int[] {left+1, right+1};
        }

        return new int[] {};
        
        
        // HashMap<Integer, Integer> map = new HashMap<>();
        // int sum = 0, left = 0, right = numbers.length - 1;
        // while(left < right){
        //     sum = numbers[left] + numbers[right];
        //     if(sum > target){
        //         right--;
        //     }else if(sum < target){
        //         left++;
        //     } else {
        //         return new int[] {left+1, right+1};
        //     }
        //     sum = 0;
        // }
        // return new int[] {};
    }
}