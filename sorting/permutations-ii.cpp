class Solution {
    void backtrack(set<vector<int>>& result, vector<int>& curr,
    vector<bool>& used, vector<int>& nums){

        //made 1 permutation
        if(curr.size() == nums.size()){
            result.insert(curr);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used[i]) continue;

            used[i] = true;
            curr.push_back(nums[i]);
            backtrack(result, curr, used, nums);
            curr.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result;
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        backtrack(result, curr, used, nums);

        return vector<vector<int>>(result.begin(), result.end());
    }
};