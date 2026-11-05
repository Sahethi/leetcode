class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(n, m, grid, i, j);
                }
            }
        }

        return islands;
    }

    void dfs(int n, int m, vector<vector<char>>& grid, int i, int j){
        if(i >=0 && i<n && j>=0 && j<m && grid[i][j] == '1'){
            grid[i][j] = '0';
            dfs(n, m, grid, i+1, j);
            dfs(n, m, grid, i-1, j);
            dfs(n, m, grid, i, j+1);
            dfs(n, m, grid, i, j-1);
        }
    }
};