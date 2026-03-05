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

        for(int i=1; i<=totalElements; i++){
            if(freq[i] == 2){
                res.push_back(i);
            }
        }

        for(int i=1; i<=totalElements; i++){
            if(freq[i] == 0){
                res.push_back(i);
            }
        }

        return res;
    }
};