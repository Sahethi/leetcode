class Solution {

    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result){
        result.push_back(current);

        for(int i=start; i<nums.size(); i++){
            current.push_back(nums[i]);
            backtrack(i+1, nums, current, result);
            current.pop_back();
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, nums, current, result);

        int xorOfAllSubsets;
        int sum = 0;
        for(auto& list : result){
            xorOfAllSubsets = 0;
            for(int n : list){
                xorOfAllSubsets ^= n;
            }
            sum += xorOfAllSubsets;
        }

        return sum;
        



        // int orOfAll = 0;
        // for(int num : nums){
        //     orOfAll |= num;
        // }

        // //2^(n-1)
        // int multiplier = 1 << (nums.size()-1);

        // return orOfAll * multiplier;
    }
};