class Solution {

    public int numIslands(char[][] grid) {
        if(grid.length == 0)
            return 0;

        //m is number of node
        //n is edges
        int n = grid.length;
        int m = grid[0].length;

        int[][] vis = new int[n][m];
        int count = 0;

        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    count++;
                    dfs(n, m, vis, grid, i, j);
                }
            }
        }
        return count;
    }

    private void dfs(int n, int m, int[][] vis, char[][] grid, int i, int j){
        if( i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0 && grid[i][j] == '1'){
            vis[i][j] = 1;
            dfs(n, m, vis, grid, i + 1, j);    
            dfs(n, m, vis, grid, i - 1, j); 
            dfs(n, m, vis, grid, i, j + 1); 
            dfs(n, m, vis, grid, i, j - 1);       
        }
    }
}