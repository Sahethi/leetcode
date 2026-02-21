class Solution {
    public int majorityElement(int[] nums) {
        int res = 0;
        int max = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<nums.length; i++){
           map.put(nums[i], 1 + map.getOrDefault(nums[i], 0));
            if(map.get(nums[i]) > max){
                max = map.get(nums[i]);
                res = nums[i];
            }
        }
        return res;
    }
}