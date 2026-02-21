class Solution {
    public int search(int[] nums, int target) {
        
        int mid = 0, left = 0, right = nums.length - 1;
        while (left < right){
            mid = (left + right) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid; 
        }

        int min = left;
        left = 0;
        right = nums.length - 1;
        //find where the target is
        if (target >= nums[min] && target <= nums[right]) left = min;
        else right = min;
        
        return binarySearch(nums, left, right, target);
    }

    private int binarySearch(int nums[], int left, int right, int target){
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] <= target) left = mid + 1; 
            else right = mid - 1;
        }
        return -1;
    }
}