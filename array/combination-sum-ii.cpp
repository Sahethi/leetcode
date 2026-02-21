class Solution {
private: 
    void backtrack(int start, vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current){
        if(target == 0){
            result.push_back(current);
        }

        for(int i=start; i<candidates.size(); i++){
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if(candidates[i] <= target){
                current.push_back(candidates[i]);
                backtrack(i+1, candidates, target - candidates[i], result, current);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target, result, current);
        return result;
    }
};