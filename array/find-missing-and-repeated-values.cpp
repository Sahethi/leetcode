class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> res;
        vector<int> freq(n*n+1, 0);

        for(auto& row : grid){
            for(int i=0; i<n; i++){
                freq[row[i]]++;
            }
        }

        int skipped, twice;
        for(int i=1; i<=n*n; i++){
            if(freq[i] == 2){
                twice = i;
            }
            if(freq[i] == 0){
                skipped = i;
            }
        }

        res.push_back(twice);
        res.push_back(skipped);
        return res;
    }
};