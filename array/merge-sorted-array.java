class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int right1 = m-1;
        int right2 = n-1;
        int len = nums1.length - 1;
        while(right2 >= 0){
            if(right1 >=0 && nums1[right1] > nums2[right2]){
                nums1[len--] = nums1[right1];
                right1--;
            } else {
                nums1[len--] = nums2[right2];
                right2--;
            }
        } 

    }
}