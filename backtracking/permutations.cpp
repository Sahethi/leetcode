class Solution {
private:
    void backtrack(vector<bool>& used, vector<int>& nums, vector<int>& current, vector<vector<int>>& result){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;

            used[i] = true;
            current.push_back(nums[i]);
            backtrack(used, nums, current, result);
            current.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(used, nums, current, result);
        return result;
    }
};