class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> paddedGrid(m+2, vector<int>(n+2, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                paddedGrid[i][j] = grid[i-1][j-1];
            }
        }

        int peri = 0;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(paddedGrid[i][j] == 1){
                    if(paddedGrid[i-1][j] == 0){
                        peri++;
                    }
                    if(paddedGrid[i+1][j] == 0){
                        peri++;
                    }
                    if(paddedGrid[i][j-1] == 0){
                        peri++;
                    }
                    if(paddedGrid[i][j+1] == 0){
                        peri++;
                    }
                }
            }
        }

        return peri;
    }
};