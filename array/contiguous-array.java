class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int sum = 0;
        int maxLen = 0;
        for(int i=0; i<nums.length; i++){
            if(nums[i] == 0)
                sum--;
            if(nums[i] == 1)
                sum++;
            if(sum == 0){
                maxLen = i + 1;
            } else if(map.containsKey(sum)){
                maxLen = Math.max(maxLen, i - map.get(sum));
            } else {
                map.put(sum, i);
            }
        }
        return maxLen;
    }
}