class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //work on smaller array
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high =m;
        int leftSize = (m+n+1)/2;

        while(low <= high){
            int i = (low + high) / 2;
            int j = leftSize - i;

            // 0 ..... i-1 . i .......m
            int nums1_left_max = i==0 ? INT_MIN : nums1[i-1];
            int nums1_right_min = i==m ? INT_MAX : nums1[i];
            int nums2_left_max = j==0 ? INT_MIN : nums2[j-1];
            int nums2_right_min = j==n ? INT_MAX : nums2[j];

            //we have the perfect partition
            if(nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min){
                if((m+n) % 2 == 1){
                    return max(nums1_left_max, nums2_left_max);
                }else{
                    return (
                        max(nums1_left_max, nums2_left_max) +
                        min(nums1_right_min, nums2_right_min)) / 2.0;
                }
            }

            //if the partition is right

            //took too many elements from A
            else if(nums1_left_max > nums2_right_min){
                high = i - 1;
            }else{
                //took too many elemenents from b
                low = i+1;
            }
        }

        return 0.0;
    }
};