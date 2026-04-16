class Solution {
public:
    void backtrack(vector<int>& comb, vector<vector<int>>& res, int n, int k, int start){
        if(comb.size() == k){
            res.push_back(comb);
            return;
        }

        for(int i=start; i<=n; i++){
            comb.push_back(i);
            backtrack(comb, res, n, k, i+1);
            comb.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;

        backtrack(comb, res, n, k, 1);
        return res;
    }
};