class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long z1 = 0, z2 = 0;

        for (int x : nums1) {
            if (x == 0) z1++;
            else sum1 += x;
        }

        for (int x : nums2) {
            if (x == 0) z2++;
            else sum2 += x;
        }

        long long min1 = sum1 + z1;
        long long min2 = sum2 + z2;

        if (min1 == min2) return min1;

        if (min1 < min2) {
            if (z1 == 0) return -1;
            return min2;
        } else {
            if (z2 == 0) return -1;
            return min1;
        }
    }
};