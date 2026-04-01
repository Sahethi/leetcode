class Solution {

    int backtrack(int i, int sum, vector<int>& nums){
        int n = nums.size();
        if(i == n) return sum;

        return backtrack(i+1, sum ^ nums[i], nums) + backtrack(i+1, sum, nums);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        
        return backtrack(0, 0, nums);

    
        



        // int orOfAll = 0;
        // for(int num : nums){
        //     orOfAll |= num;
        // }

        // //2^(n-1)
        // int multiplier = 1 << (nums.size()-1);

        // return orOfAll * multiplier;
    }
};