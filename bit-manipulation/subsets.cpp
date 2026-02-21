class Solution {
private:
    void backtrack(int start, vector<int>& current, vector<int>& nums, vector<vector<int>>& result){
        result.push_back(current);
        for(int i = start; i < nums.size(); i++){
            current.push_back(nums[i]);
            backtrack(i+1, current, nums, result);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, current, nums, result);
        return result;
    }
};