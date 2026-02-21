class Solution {
    public int[] twoSum(int[] nums, int target) {
        //create a hashmap, with key as number and alue as index
        // target = num[i] + num[j]
        //num[j] = target - num[i]
        int diff = 0;
        Map<Integer, Integer> numIndex = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            diff = target - nums[i];
            if(numIndex.containsKey(diff))
                return new int[] {numIndex.get(diff), i};

            numIndex.put(nums[i], i);
        }

        return new int[] {};
        
    }
}