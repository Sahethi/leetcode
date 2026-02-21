class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int dp_1 = 1;
        int dp_2 = 1;
        int ans=1;
        for(int i=1; i<n; i++){

            int new_dp_1 = 1, new_dp_2 = 1;

            if(nums1[i] >= nums1[i-1]){
                new_dp_1 = max(new_dp_1, dp_1+1);
            }
            if (nums1[i] >= nums2[i-1]){
                new_dp_1 = max(new_dp_1, dp_2+1);
            }

            if(nums2[i] >= nums1[i-1]){
                new_dp_2 = max(new_dp_2, dp_1+1);
            }
            if (nums2[i] >= nums2[i-1]){
                new_dp_2 = max(new_dp_2, dp_2+1);
            }

            dp_1 = new_dp_1;
            dp_2 = new_dp_2;


            ans = max(ans, max(dp_1, dp_2));

        }
        return ans;
    }
};