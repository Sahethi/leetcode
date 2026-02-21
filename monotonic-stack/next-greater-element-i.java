class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        
        //nums2 needs to get pushed on stack
        //nums1 will get compared

        int[] ans = new int[nums1.length];
        //creating a monotonic stack
        Stack<Integer> stack = new Stack<>();
        //storing value and index
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<nums2.length; i++){
            while(!stack.isEmpty() && stack.peek() < nums2[i]){
                map.put(stack.pop(), nums2[i]);
            }
            stack.add(nums2[i]);
        }
        
        for(int i=0; i<nums1.length; i++){
            ans[i] = map.getOrDefault(nums1[i], -1);
        }
        
        return ans;
    }
}