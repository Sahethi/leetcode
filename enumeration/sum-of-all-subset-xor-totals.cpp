class Solution {

    int backtrack(int i, int sum, vector<int>& nums){
        int n = nums.size();
        if(i == n) return sum;
        return backtrack(i+1, sum ^ nums[i], nums) + backtrack(i+1, sum, nums);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        
        // return backtrack(0, 0, nums);

        //bit manipulation solution
        int orAns = 0;
        int n = nums.size();
        for(int num : nums){
            orAns |= num;
        }

        int ans = orAns * (1 << (n-1));

        return ans;
    }
};