class Solution {
private:
    void backtrack(int start, vector<int>& candidates, int target, vector<vector<int>> &result, vector<int> &current){
        if(target == 0){
            result.push_back(current);
            return;
        }

        for(int i=start; i<candidates.size(); i++){
            if(candidates[i] <= target){
                current.push_back(candidates[i]);
                backtrack(i, candidates, target - candidates[i], result, current);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, candidates, target, result, current);

        return result;
    }
};