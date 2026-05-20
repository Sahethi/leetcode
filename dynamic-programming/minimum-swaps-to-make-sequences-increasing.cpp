class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int keep=0, swap=1;

        for(int i=1; i<n; i++){
            int newKeep = INT_MAX;
            int newSwap = INT_MAX;

            //normal condition
            if(nums1[i-1] < nums1[i] && nums2[i-1] < nums2[i]){
                newKeep = min(newKeep, keep);
                newSwap = min(newSwap, swap+1);
            }

            //cross condition
            if(nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i]){
                newKeep = min(newKeep, swap);
                newSwap = min(newSwap, keep+1);
            }

            keep = newKeep;
            swap = newSwap;
        }

        return min(keep, swap);
    }
};