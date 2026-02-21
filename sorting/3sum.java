class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //works on a sorted array
        Arrays.sort(nums);
        int sum = 0;
        List<List<Integer>> result = new ArrayList<>();
        for(int i=0; i<nums.length-2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i + 1;
            int right = nums.length - 1;

            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                if(sum < 0){
                    left++;
                } else if (sum > 0){
                    right--;
                } else {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++;
                    right--;
                    //if left has duplicate
                    while(left < right && nums[left] == nums[left-1])
                        left++;
                }
            }
            
        }
        return result;
    }
}