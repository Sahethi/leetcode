class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 1) return {{1}};
        if(numRows >= 2) {
            result.push_back({1});
            result.push_back({1,1});
        }

        for(int i=1; i<numRows-1; i++){
            vector<int> ans;
            ans.push_back(1);
            int sum =0;
            for(int j=0; j<result[i].size()-1; j++){
                sum = result[i][j] + result[i][j+1];
                ans.push_back(sum);
            }
            ans.push_back(1);
            result.push_back(ans);
        }
        return result;
    }
};