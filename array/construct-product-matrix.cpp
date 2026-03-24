class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prodMat(m, vector<int>(n));

        long long ans= 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans *= grid[i][j];
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                prodMat[i][j] = (ans / grid[i][j]) % 12345;
            }
        }

        return prodMat;
    }
};