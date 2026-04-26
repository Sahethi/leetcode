class Solution {
public:
    int rows, cols;
    vector<vector<bool>> visited;

    bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid){
        visited[r][c] = true;

        //directions to explore the cells left, right, up, down
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for(auto [dr, dc] : directions){
            int nr = r + dr;
            int nc = c + dc;

            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols 
            && grid[nr][nc] == grid[r][c]){
                //exploring neighbors
                if(!visited[nr][nc]){
                    if(dfs(nr, nc, r, c, grid)) return true;
                } 
                //basically its visited and not parent then we found cycle
                else if (nr != pr && nc != pc){
                    return true;
                }
            }
        }
        return false;

    }

    bool containsCycle(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        visited.assign(rows, vector<bool>(cols, false));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(!visited[i][j]){
                    if(dfs(i, j, -1, -1, grid)) return true;
                }
            }
        }

        return false;
    }
};