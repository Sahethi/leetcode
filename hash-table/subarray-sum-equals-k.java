class Solution {
    public int subarraySum(int[] nums, int k) {
        int prefixSum = 0;
        int count = 0;
        //preSum and count
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0,1);
        for(int i=0; i<nums.length; i++){
            prefixSum += nums[i];
            int remove = prefixSum - k;
            if(map.containsKey(remove)){
                count += map.get(remove);
            }
            map.put(prefixSum, map.getOrDefault(prefixSum, 0) + 1);
        }

        return count;
        
        // int result = 0;
        // int sum = 0;
        // Map<Integer, Integer> prefixSum = new HashMap<>();
        // prefixSum.put(0,1);

        // for (int num : nums){
        //     //current sum
        //     sum += num;
        //     //difference
        //     int diff = sum - k;
        //     if(prefixSum.containsKey(diff)){
        //         result += prefixSum.get(diff);
        //     }
        //     prefixSum.put(sum, prefixSum.getOrDefault(sum, 0) + 1);
        // }
        // return result;
    }
}