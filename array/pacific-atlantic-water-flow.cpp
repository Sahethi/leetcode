class Solution {
private:
    void dfs(int r, int c, int prevHeight, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        int m = heights.size(); // rows
        int n = heights[0].size(); // cols

        if(r < 0 || r >=m || c < 0 || c >= n || prevHeight > heights[r][c] || visited[r][c]){
            return;
        }

        visited[r][c] = true;

        dfs(r+1, c, heights[r][c], heights, visited);
        dfs(r-1, c, heights[r][c], heights, visited);
        dfs(r, c+1, heights[r][c], heights, visited);
        dfs(r, c-1, heights[r][c], heights, visited);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size(); // rows
        int n = heights[0].size(); // cols

        //declaring a matrix for pacific
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        //moving top to bottom horizontally
        for(int c=0; c<n; c++){
            dfs(0, c, heights[0][c], heights, pacific); // top row
            dfs(m-1, c, heights[m-1][c], heights, atlantic); // bottom row
        }

        //moving left to right vertically
        for(int r=0; r<m; r++){
            dfs(r, 0, heights[r][0], heights, pacific);
            dfs(r, n-1, heights[r][n-1], heights, atlantic);
        }


        vector<vector<int>> result;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};