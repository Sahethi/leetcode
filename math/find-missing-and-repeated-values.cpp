class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int totalElements = n * grid.size();
        vector<int> res;
        unordered_map<int, int> freq;

        for(auto& row : grid){
            for(int i=0; i<n; i++){
                freq[row[i]]++;
            }
        }

        int skipped, twice;
        for(int i=1; i<=totalElements; i++){
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