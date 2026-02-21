class Solution {
private:
    void backtrack(int start, int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>& current){

        if(target == 0){
            result.push_back(current);
            return;
        }

        for(int i=start; i<candidates.size(); i++){
            if(candidates[i] <= target){
                current.push_back(candidates[i]);
                backtrack(i, target - candidates[i], candidates, result, current);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, result, current);
        return result;
    }
};