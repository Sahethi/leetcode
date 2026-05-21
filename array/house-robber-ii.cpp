class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(
            robHouse(0, n-2, nums),
            robHouse(1, n-1, nums)
        );
    }

    int robHouse(int start, int end, vector<int>& nums){
        int prev2 = 0, prev1 = 0;

        for(int i=start; i<=end; i++){
            int curr = max(prev2+nums[i], prev1);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};