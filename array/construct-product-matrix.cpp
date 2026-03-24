class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;
        vector<vector<int>> prodMat(m, vector<int>(n, 1));

        // result[i] = (product of left) * (product of right)

        int prefix = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                prodMat[i][j] = prefix;
                prefix = (prefix * grid[i][j]) % mod;
            }
        }

        int suffix = 1;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                prodMat[i][j] = (prodMat[i][j] * suffix) % mod;
                suffix = (suffix * grid[i][j]) % mod; 
            }
        }

        return prodMat;
    }
};