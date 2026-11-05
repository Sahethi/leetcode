class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        //find median
        int totalMoves = 0;
        int n = nums.size();
        //works for both even and odd length
        int median = nums[n/2];

        for(int num : nums){
            totalMoves += abs(num - median);
        }

        return totalMoves;
    }
};