class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        int zeroNum1 = 0;
        long long minSumNum1 = 0;
        for(int num1: nums1){
            if(num1 == 0)
                zeroNum1++;
            minSumNum1 += num1;
        }
        minSumNum1 += zeroNum1;

        int zeroNum2 = 0;
        long long minSumNum2 = 0;
        for(int num2: nums2){
            if(num2 == 0)
                zeroNum2++;
            minSumNum2 += num2;
        }
        minSumNum2 += zeroNum2;

        if(minSumNum1 == minSumNum2) return minSumNum1;
        if((minSumNum1 < minSumNum2) && (zeroNum1 == 0)) return -1;
        if((minSumNum2 < minSumNum1) && (zeroNum2 == 0)) return -1;
        
        return max(minSumNum1,minSumNum2);
    }
};