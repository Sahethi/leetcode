class Solution {
    public boolean containsDuplicate(int[] nums) {
        // Map<Integer, Integer> map = new HashMap<>();
        // for(int i=0; i<nums.length; i++){
        //     if(map.containsKey(nums[i]) && map.get(nums[i]) >=1 )
        //         return true;
        //     map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        // }
        // return false;
        Set<Integer> hset = new HashSet<>();
        for (int num : nums){
            if(hset.contains(num))
                return true;
            hset.add(num);
        }
        return false;
    }
}